#ifndef OOP_RGZ_CHARACTER_H
#define OOP_RGZ_CHARACTER_H

#include <utility>
#include "Entity.h"
#include "../Map/Map.h"
//#include "../Game/Game.h"

class Character : public Entity {
public:
    Character() = default;

    Character(AnimationManager &am, size_t maxHp, float x = 0, float y = 0);

    size_t getHp() const;

    void setHp(size_t value);;

    void damage(size_t damage);

    void heal(size_t value);

    void heal();

    void kill();

    bool onGround() const;

    void setOnGround(bool onGround);

    virtual void moveLeft();

    virtual void moveRight();

    virtual void jump();

    virtual void stop();

    void update(float time) override;

protected:
    virtual void setAnimationByState();

    virtual void resolveCollisions(const Map &map, bool isHorizontalDirection);

protected:
    enum {
        LEFT, RIGHT
    } xDirection {};

    enum {
        STAY, WALK, JUMP
    } state {};

    bool dirChanged{false};
private:
    bool isOnGround{false};
    size_t maxHp{};
    size_t hp{};
    constexpr static const double ACCELERATION = 10;
};


#endif //OOP_RGZ_CHARACTER_H
