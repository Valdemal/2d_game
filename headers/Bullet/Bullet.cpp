#include "Bullet.h"
#include "../Settings.h"
#include "../Level/Level.h"

Bullet::Bullet(float x, float y, size_t damage, direction_t direction) : damage(damage) {
    setPos(x, y);
    setXDirection(direction);

    setAnimationManager(settings::bullet::STANDARD_AM);
    getAnimationManager().set("move");

    setDx(direction == RIGHT ? ACCELERATION : -ACCELERATION);
}

void Bullet::damageTo(Enemy &enemy) {
    enemy.damage(this->damage);
    explode();
}

void Bullet::update(float time) {
    setX(getX() + getDx() * time);

    auto& map = Level::getInstance()->getMap();

    for (size_t i = std::abs(getY() / float(settings::TILE_SIZE));
         i < std::abs((getY() + height()) / float(settings::TILE_SIZE)); i++)

        for (size_t j = std::abs(getX() / float(settings::TILE_SIZE));
             j < std::abs((getX() + width()) / float(settings::TILE_SIZE)); j++) {
            if (map[i][j] == mapObject::Border) {
                explode();
            }
        }

    getAnimationManager().tick(time);
}

std::string Bullet::type() const {
    return "Bullet";
}

void Bullet::explode() {
    setDx(0);
    getAnimationManager().set("explode");
    setAlive(false);
}
