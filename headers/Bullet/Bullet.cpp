#include "Bullet.h"
#include "../Settings.h"

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

AnimationManager Bullet::createBulletAnimation() {
    AnimationManager anim;
    sf::Texture t;
    t.loadFromFile(settings::PLAYER_TEXTURE_FILE);
    anim.create("move",Animation(t,sf::IntRect (247,582,8,8),1,0,0));
    anim.create("explode",Animation(t, sf::IntRect(323,583,18,18),4,0.01,29));
    return anim;
}
