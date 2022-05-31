#ifndef ENEMY_CLONE
#define ENEMY_CLONE

#include "Enemy.hpp"
//#include "../Player/Player.h"

class Clone : public Enemy {
private:
    const size_t DAMAGE = 30;
public:
    explicit Clone(float x = 0, float y = 0) {
        setPos(x, y);
        am = settings::PLAYER_AM;
        am.set("stay");
        xDirection = LEFT;
    }
//
//    void attack(Player &player) override {
//        player.damage(DAMAGE);
//    }
};

#endif