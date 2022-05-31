#include "Bullet.h"

Bullet::Bullet(float x, float y, size_t damage, bool isRightDirection) : damage(damage) {

    setPos(x, y);
    am = createBulletAnimation();
    am.set("move");
    setDx(isRightDirection ? ACCELERATION : -ACCELERATION);
}

void Bullet::damageTo(Character &character) {
    character.damage(this->damage);
    setAlive(false);
}

void Bullet::update(float time) {
    setX(getX() + getDx() * time);

    if (true) {
//        auto map = Game::getInstance().getMap();
//
//        for (size_t i = size_t(getY()) / settings::TILE_SIZE; i < (getY() + height()) / settings::TILE_SIZE; ++i)
//            for (size_t j = size_t(getX()) / settings::TILE_SIZE;
//                 j < (getX() + width()) / settings::TILE_SIZE; ++j) {
//                if (map[i][j] == mapObject::Border) {
//                    setDx(0);
//                    setAlive(false);
//                    am.set("explode");
//                }
//            }
    }
    am.tick(time);
}

std::string Bullet::type() const {
    return "Bullet";
}
