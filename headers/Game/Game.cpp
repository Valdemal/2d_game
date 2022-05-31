#include "Game.h"


Game *Game::instance = nullptr;

Game::Game(Map &map, Player &player) : map(map), player(player) {
    if (not instance) {
        instance = this;

        parseMap();
        // Добавление всплывающих сообщений
        Message pauseMessage("Pause", 45, settings::game::window::WIDTH / 2, 50);
        pauseMessage.setColor(sf::Color::Red);
        ui.add("pause", pauseMessage);

        TemporaryMessage tm("Start", 45, 2, settings::game::window::WIDTH / 2, 50);
        tm.setColor(sf::Color::Red);
        ui.show(tm);
    } else
        throw std::runtime_error("Trying to create second singleton!");
}


void Game::processEvent(const sf::Event &event) {
    if (isRunning()) {
        if (event.type == sf::Event::KeyPressed) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                pause();
                ui.getMessage("pause").activate();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                player.shoot();
            }
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player.moveRight();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player.moveLeft();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            player.jump();
        } else {
            // Переделать
            player.stop();
        }
    } else {
        if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            start();
            ui.getMessage("pause").deactivate();

            TemporaryMessage tm("Start", 45, 2, settings::game::window::WIDTH / 2, 50);
            tm.setColor(sf::Color::Red);
            ui.show(tm);
        }
    }
}

bool Game::isRunning() const {
    return running;
}

void Game::start() {
    running = true;
}

void Game::pause() {
    running = false;
}

void Game::finish() {
    running = false;
    finished = true;
}

bool Game::isFinished() const {
    return finished;
}

Game &Game::getInstance() {
    if (!instance)
        throw std::runtime_error("Game is not initialized!");

    return *instance;
}

void Game::draw(sf::RenderWindow &window) {
    player.draw(window);
    map.draw(window);
    ui.draw(window);

    for (auto &entity : entities) {
        entity->draw(window);
    }
}

void Game::update(float time) {
    if (isRunning()) {
        player.update(time);

        for (const auto &entity : entities)
            entity->update(time);

        resolveCollisionsBetweenEntities();

        if (!player.isAlive()) {
            finish();
            std::cout << "Game over!";
        }
    }
}

const Map &Game::getMap() {
    return map;
}

void Game::addEntity(const entityPtr &entity) {
    entities.push_back(entity);
}

void Game::parseMap() {
    for (size_t i = 0; i < map.rows(); ++i) {
        for (size_t j = 0; j < map.cols(); ++j) {
            if (map[i][j] != mapObject::Empty && map[i][j] != mapObject::Border)
                addEntity(EntityFactory::create(map[i][j],
                                                float(j - 1) * settings::TILE_SIZE,
                                                float(i - 1) * settings::TILE_SIZE));
        }
    }
}

void Game::resolveCollisionsBetweenEntities() {

    for (auto it = entities.begin(); it != entities.end();) {
        if ((*it)->isAlive()) {

            if ((*it)->type() == "Bullet") {
                auto bullet = dynamic_cast<Bullet &>(**it);

                for (auto &entity : entities)
                    if (entity->type() == "Enemy" and bullet.intersects(*entity)) {
                        bullet.damageTo(dynamic_cast<Enemy &>(*entity));
                        bullet.setAlive(false);
                        std::cout << "Bullet hit to!";
                    }

            } else if ((*it)->type() == "Enemy" and (*it)->intersects(player)) {
                auto enemy = dynamic_cast<Enemy*>(it->get());
                std::cout << "Enemy should attack player" << std::endl;
                // Тут логика атаки, которая пока не работает по странным причинам

            } else if ((*it)->type() == "Modifier" and (*it)->intersects(player)) {
                std::cout << "Modify";
                auto modifier = dynamic_cast<Modifier*>(it->get());
                modifier->useOn(player);
            }

            it++;
        } else
            it = entities.erase(it);
    }
}

