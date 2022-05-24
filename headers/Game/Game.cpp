#include "Game.h"


Game* Game::instance = nullptr;

const std::string Game::PLAYER_TEXTURE_FILE = "../files/fang.png";

void Game::processEvent(const sf::Event &event) {
//    auto key = event.key.code;
    if (isRunning()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            pause();
            std::cout << "Pause" << std::endl;
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player.moveRight();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player.moveLeft();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            player.jump();
        } else if (isNum(event.key.code)) {
            std::cout << "num " << (event.key.code - sf::Keyboard::Num0) << std::endl;
        }
    } else {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            start();
            std::cout << "Lets go!!" << std::endl;
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

Game::Game(Map &map) : map(map) {
    sf::Texture texture;
    texture.loadFromFile(PLAYER_TEXTURE_FILE);

    player = Player(texture,
                    sf::FloatRect(0,0,40,50),
                    std::make_pair(32,  SETTINGS.game.window.height - SETTINGS.TILE_SIZE));

    instance = this;
}

bool Game::isNum(const sf::Keyboard::Key &key) {
    return key >= sf::Keyboard::Num0 and key <= sf::Keyboard::Num9;
}

Game &Game::getInstance() {
    if (!instance)
        throw std::runtime_error("Game is not initialized!");

    return *instance;
}

void Game::draw(sf::RenderWindow &window) {
    player.draw(window);
    map.draw(window);
}

void Game::update(float time) {
    if (isRunning()){
        player.update(time, map);
    }
}

