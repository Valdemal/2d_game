#ifndef ENEMY_CLONE
#define ENEMY_CLONE

#include "Enemy.hpp"

class Clone : public Enemy {
private:
    const size_t DAMAGE = 30;
public:
    explicit Clone(float x = 0, float y = 0);

    void attack(Player &player) override;
};


#endif