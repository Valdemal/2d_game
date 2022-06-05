#ifndef OOP_RGZ_ENTITY_H
#define OOP_RGZ_ENTITY_H

#include "../Animation/AnimationManager.h"

typedef enum {
    LEFT, RIGHT
} direction_t;

class Entity {
public:
    Entity() = default;

    explicit Entity(const AnimationManager &am, float x = 0, float y = 0);

    virtual std::string type() const = 0;

    float getDx() const;

    float getDy() const;

    float getX() const;

    float getY() const;

    float width() const;

    float height() const;

    AnimationManager& getAnimationManager();

    direction_t getXDirection() const;

    bool isAlive() const;

    bool intersects(const Entity &other) const;

    virtual void update(float time);

    virtual void draw(sf::RenderWindow &window);

    void setPos(float x, float y);

    void setX(float x);

    void setY(float y);

    void setAlive(bool isAlive);

    void increaseDx(float value);

    void increaseDy(float value);

    void setDx(float acceleration);

    void setDy(float acceleration);

    void setXDirection(direction_t dir);

    void setAnimationManager(const AnimationManager &am);

private:
    AnimationManager animationManager;
    float dx{0}, dy{0};
    float x{}, y{};
    bool alive{true};
    direction_t xDirection{};

    struct compareRectStruct {
        float x, y;
        float x1, y1;
    };

    static bool checkIntersection(compareRectStruct a, compareRectStruct b);
};


#endif //OOP_RGZ_ENTITY_H
