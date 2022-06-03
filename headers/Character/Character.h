#ifndef OOP_RGZ_CHARACTER_H
#define OOP_RGZ_CHARACTER_H

#include <utility>
#include "../Entity/Entity.h"

class Map;

class Character : public Entity {
public:
    Character() = default;

    Character(const AnimationManager &am, size_t maxHp, float x = 0, float y = 0);

    size_t getHp() const;

    size_t getMaxHp() const;

    void setHp(size_t value);

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
    typedef enum {
        LEFT, RIGHT
    } direction_t;

    direction_t xDirection{};

    enum {
        STAY, WALK, JUMP
    } state{};

    bool dirChanged{false};

protected:

    virtual void move(direction_t direction);

    virtual void setAnimationByState();

    virtual void resolveCollisions(const Map &map, bool isHorizontalDirection);

private:
    bool isOnGround{false};
    size_t maxHp{};
    size_t hp{};


    constexpr static const double X_ACCELERATION = 10;
    constexpr static const float Y_ACCELERATION = 0.0005f;
    constexpr static const float JUMP_ACCELERATION = -0.27;
};


#endif //OOP_RGZ_CHARACTER_H
