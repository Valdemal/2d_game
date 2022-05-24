#include "Player.h"

Player::Player(sf::Texture &image, sf::FloatRect textureRect, std::pair<float, float> position) {

    sprite.setTexture(image);
    sprite.setColor(sf::Color::Green);
    sprite.setPosition(position.first,  position.second);
    rect = textureRect;

    dx = dy = 0;
    currentFrame = 0;
}

void Player::moveLeft() {
    dx = -ACCELERATION;
}

void Player::moveRight() {
    dx = ACCELERATION;
}

void Player::update(float time, const Map &map) {
    rect.left += dx * time;
    resolveCollisions(map, true);

    if (!onGround)
        dy += 0.0005f * time;

    rect.top += dy * time;
    onGround = false;
    resolveCollisions(map, false);

    currentFrame += 0.005f * time;
    if (currentFrame > 6)
        currentFrame -= 6;

    if (dx > 0)
        sprite.setTextureRect(sf::IntRect(40*int(currentFrame), 4, 40, 50));

    if (dx < 0)
        sprite.setTextureRect(sf::IntRect(40*int(currentFrame) + 40, 40, -40, 50));


    sprite.setPosition(rect.left, rect.top);
    dx = 0;
}

void Player::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

void Player::jump() {
    if (onGround){
        dy = -0.4;
        onGround = false;
    }
}

void Player::resolveCollisions(const Map &map, bool isHorizontalDirection) {
    for (size_t i = rect.top / int(SETTINGS.TILE_SIZE); i < (rect.top + rect.height) / SETTINGS.TILE_SIZE; i++)
        for (size_t j = rect.left / SETTINGS.TILE_SIZE; j < (rect.left + rect.width) / SETTINGS.TILE_SIZE; j++) {

            // Обработка столкновения с границей
            if (map[i][j] == mapObject::Border){
                if (isHorizontalDirection){
                    if (dx > 0)
                        rect.left = j * SETTINGS.TILE_SIZE - rect.width;
                    else if (dx < 0)
                        rect.left = j * SETTINGS.TILE_SIZE + SETTINGS.TILE_SIZE;
                } else {
                    if (dy > 0){
                        rect.top = i * SETTINGS.TILE_SIZE - rect.height;
                        dy = 0;
                        onGround = true;
                    } else if (dy < 0) {
                        rect.top = i * SETTINGS.TILE_SIZE +  SETTINGS.TILE_SIZE;
                        dy = 0;
                    }
                }
            }
        }
}
