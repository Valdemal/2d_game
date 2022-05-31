#ifndef OOP_RGZ_ENTITY_H
#define OOP_RGZ_ENTITY_H


#include <utility>

#include "../Animation/AnimationManager.h"

class Entity {
protected:
    AnimationManager am;
private:
    float dx{0}, dy{0};
    float x{}, y{};
    bool alive{true};
public:
    Entity()=default;

    explicit Entity(AnimationManager &am, float x = 0, float y = 0) : am(am), x(x), y(y) {};

    bool intersects(const Entity& other) const;

    void setPos(float x, float y);

    void setX(float x);

    void setY(float y);

    void setAlive(bool isAlive);

    bool isAlive() const {
        return alive;
    }

    float getDx() const {
        return dx;
    }

    float getDy() const {
        return dy;
    }

    void increaseDx(float value) {
        dx += value;
    }

    void increaseDy(float value) {
        dy += value;
    }

    void setDx(float acceleration) {
        this->dx = acceleration;
    }

    void setDy(float acceleration){
        this->dy = acceleration;
    }

    float getX() const;

    float getY() const;

    float width () const;

    float height() const;

    virtual void draw(sf::RenderWindow& window);

    virtual void update(float time) = 0;

    virtual std::string type() const = 0;
};


#endif //OOP_RGZ_ENTITY_H
