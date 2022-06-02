#ifndef OOP_RGZ_BULLET_H
#define OOP_RGZ_BULLET_H

#include "../Character/Character.h"

class Bullet : public Entity {
private:
    size_t damage;

    const float ACCELERATION = 10;

public:
    Bullet(float x, float y, size_t damage, bool isRightDirection);

    void damageTo(Character &character);

    void update(float time) override;

    std::string type() const final;

private:
    // У всех пуль одна и та же анимация
    static AnimationManager createBulletAnimation();
};


#endif //OOP_RGZ_BULLET_H
