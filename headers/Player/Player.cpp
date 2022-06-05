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
