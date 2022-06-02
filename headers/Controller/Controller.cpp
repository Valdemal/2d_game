#include "Controller.h"

void Controller::processEvent(const sf::Event &event) {
    if (isRunning()) {
        if (event.type == sf::Event::KeyPressed) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                pause();
                ui.getMessage("pause").activate();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                level->getPlayer().shoot();
            }
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            level->getPlayer().moveRight();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            level->getPlayer().moveLeft();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            level->getPlayer().jump();
        } else {
            // Переделать
            level->getPlayer().stop();
        }
    } else {
        if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            start();
            ui.getMessage("pause").deactivate();

            TemporaryMessage tm("Start", 45, 2, float(settings::game::window::WIDTH) / 2, 50);
            tm.setColor(sf::Color::Red);
            ui.show(tm);
        }
    }
}

bool Controller::isRunning() const {
    return running;
}

void Controller::start() {
    running = true;
}

void Controller::pause() {
    running = false;
}

void Controller::finish() {
    running = false;
    finished = true;
}

bool Controller::isFinished() const {
    return finished;
}

void Controller::draw(sf::RenderWindow &window) {
    level->draw(window);
    ui.draw(window);
}

void Controller::update(float time) {
    if (isRunning()) {
        level->update(time);

        if (!level->getPlayer().isAlive()) {
            finish();
            std::cout << "Game over!";
        }
    }
}

Controller::Controller() {
    auto map = Map::readFromTextFile("../files/map.txt");

    auto player = std::make_shared<Player>(settings::PLAYER_AM, 100,
                                           float(settings::game::window::WIDTH) / 2 - 60,
                                           float(settings::game::window::HEIGHT) / 2);

    level = std::make_unique<Level>(player, map);

    // Добавление всплывающих сообщений
    Message pauseMessage("Pause", 45, float(settings::game::window::WIDTH) / 2, 50);
    pauseMessage.setColor(sf::Color::Red);
    ui.add("pause", pauseMessage);

    TemporaryMessage tm("Start", 45, 2, float(settings::game::window::WIDTH) / 2, 50);
    tm.setColor(sf::Color::Red);
    ui.show(tm);
}
