#include "Controller.h"
#include "../Settings.h"

Controller::Controller() {
    auto map = Map::readFromTextFile(settings::map::FILE);

    // Создание одиночки
    Level::create(
            std::make_unique<Player>(settings::player::STANDARD_AM,
                                     100,
                                     float(100),
                                     float(settings::window::HEIGHT - 2 * settings::TILE_SIZE)),
            map);

    // Добавление всплывающих сообщений
    Message pauseMessage("Pause", 45, float(settings::window::WIDTH) / 2, 50);
    pauseMessage.setColor(sf::Color::Red);
    ui.add("pause", pauseMessage);

    Message gameOverMessage("Game over!!!", 45, float(settings::window::WIDTH) / 2, 50, false);
    gameOverMessage.setColor(sf::Color::Red);
    ui.add("game over", gameOverMessage);

    showStartMessage();
}

void Controller::showStartMessage() {
    TemporaryMessage tm("Start", 45, 2, float(settings::window::WIDTH) / 2, 50);
    tm.setColor(sf::Color::Red);
    ui.show(tm);
}

void Controller::processEvent(const sf::Event &event) {
    auto level = Level::getInstance();

    if (isRunning()) {
        if (event.type == sf::Event::KeyPressed) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                pause();
                ui.getMessage("pause").activate();
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                level->getPlayer()->shoot();
            }
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            level->getPlayer()->moveRight();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            level->getPlayer()->moveLeft();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            level->getPlayer()->jump();
        } else {
            // Переделать
            level->getPlayer()->stop();
        }
    } else {
        if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            start();
            ui.getMessage("pause").deactivate();
            showStartMessage();
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
    Level::getInstance()->draw(window);
    ui.draw(window);
}

void Controller::update(float time) {
    auto level = Level::getInstance();

    if (isRunning()) {
        level->update(time);

        if (!level->getPlayer()->isAlive()) {
            finish();
            ui.getMessage("game over").activate();
        }
    }
}