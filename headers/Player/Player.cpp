#include "Player.h"
#include "../Bullet/Bullet.h"
#include "../Level/Level.h"

Player::Player(AnimationManager am, size_t maxHp, float x, float y) : Character(am, maxHp, x, y) {

}

void Player::shoot() const {
    auto game = Level::getInstance();
    auto bullet = new Bullet(getX(), getY() - height() / 2, BULLET_DAMAGE, !xDirection);
    game.addEntity(entityPtr(bullet));
}

std::string Player::type() const {
    return "Player";
}
