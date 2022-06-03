#include "Bullet.h"
#include "../Settings.h"
#include "../Level/Level.h"

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

    auto map = Level::getInstance().getMap();

    for (size_t i = std::abs(getY() / float(settings::TILE_SIZE));
         i < std::abs((getY() + height()) / float(settings::TILE_SIZE)); i++)
        for (size_t j = std::abs(getX() / float(settings::TILE_SIZE));
             j < std::abs((getX() + width()) / float(settings::TILE_SIZE)); j++) {
            if (map[i][j] == mapObject::Border) {
                setDx(0);
                setAlive(false);
                am.set("explode");
            }
        }

    am.tick(time);
}

std::string Bullet::type() const {
    return "Bullet";
}

AnimationManager Bullet::createBulletAnimation() {
    AnimationManager anim;
    sf::Texture t;
    t.loadFromFile(settings::PLAYER_TEXTURE_FILE);
    anim.add("move", Animation(t, sf::IntRect(247, 582, 8, 8), 1, 0, 0));
    anim.add("explode", Animation(t, sf::IntRect(323, 583, 18, 18), 4, 0.01, 29));
    return anim;
}
