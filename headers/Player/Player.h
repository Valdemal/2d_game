#ifndef OOP_RGZ_PLAYER_H
#define OOP_RGZ_PLAYER_H

#include "../Character/Character.h"

class Player : public Character {
public:
    explicit Player(const AnimationManager &am, size_t maxHp, float x = 0, float y = 0);

    void shoot() const;

    std::string type() const override;

private:
    const size_t BULLET_DAMAGE = 20;
};


#endif //OOP_RGZ_PLAYER_H
