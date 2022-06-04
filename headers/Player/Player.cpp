#include "Player.h"
#include "../Bullet/Bullet.h"
#include "../Level/Level.h"

Player::Player(const AnimationManager &am, size_t maxHp, float x, float y) : Character(am, maxHp, x, y) {
}

void Player::shoot() const {
    auto level = Level::getInstance();
    auto bullet = entityPtr(new Bullet (getX()+width(), getY() + height() * 1/3, BULLET_DAMAGE, getXDirection()));
    level->addEntity(bullet);
}

std::string Player::type() const {
    return "Player";
}

AnimationManager Player::createPlayerAnimation() {
    sf::Texture texture;
    texture.loadFromFile(settings::player::TEXTURE_FILE);

    AnimationManager am;
    am.add("walk",
           Animation(texture,
                     sf::IntRect(0, 244, 40, 50),
                     6, 0.005, 40));

    am.add("jump",
           Animation(texture,
                     sf::IntRect(0, 528, 29, 30),
                     4, 0.0045, 40));

    am.add("stay", Animation(texture,
                             sf::IntRect(0, 187, 42, 52),
                             3, 0.002, 40));
    return am;
}
