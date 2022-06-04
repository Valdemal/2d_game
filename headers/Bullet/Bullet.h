#ifndef OOP_RGZ_BULLET_H
#define OOP_RGZ_BULLET_H

#include <iostream>
#include "../Enemy/Enemy.hpp"

class Bullet : public Entity {
public:
    Bullet(float x, float y, size_t damage, direction_t direction);

    void damageTo(Enemy &enemy);

    void update(float time) override;

    std::string type() const final;
protected:
    void explode();

private:
    size_t damage;

    const float ACCELERATION = 0.7;
};


#endif //OOP_RGZ_BULLET_H
