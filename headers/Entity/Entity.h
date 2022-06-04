#ifndef OOP_RGZ_ENTITY_H
#define OOP_RGZ_ENTITY_H


#include <utility>

#include "../Animation/AnimationManager.h"

class Entity {
public:
    Entity() = default;

    explicit Entity(const AnimationManager &am, float x = 0, float y = 0);

    virtual void update(float time);

    virtual std::string type() const = 0;

    bool intersects(const Entity &other) const;

    void setPos(float x, float y);

    void setX(float x);

    void setY(float y);

    void setAlive(bool isAlive);

    bool isAlive() const;

    float getDx() const;

    float getDy() const;

    void increaseDx(float value);

    void increaseDy(float value);

    void setDx(float acceleration);

    void setDy(float acceleration);

    float getX() const;

    float getY() const;

    float width() const;

    float height() const;

    virtual void draw(sf::RenderWindow &window);

    typedef enum {
        LEFT, RIGHT
    } direction_t;

    direction_t getXDirection() const;

    void setXDirection(direction_t dir);

    AnimationManager& getAnimationManager();

    void setAnimationManager(const AnimationManager &am);

protected:
    AnimationManager animationManager;
private:
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
