#ifndef OOP_RGZ_PLAYER_H
#define OOP_RGZ_PLAYER_H

#include "../Game/Game.h"
#include "../Entity/Character.h"
#include "../Bullet/Bullet.h"

class Player : public Character {
public:
    Player() = default;

    explicit Player(AnimationManager am, size_t maxHp, float x = 0, float y = 0);

    void shoot() const;

    std::string type() const {
        return "Player";
    }

private:
    const size_t BULLET_DAMAGE = 20;
};


#endif //OOP_RGZ_PLAYER_H
