#include "Entity.h"

void Entity::setPos(float x, float y) {
    setX(x);
    setY(y);
}

void Entity::setX(float x) {
    this->x = x;
}

void Entity::setY(float y) {
    this->y = y;
}

void Entity::setAlive(bool isAlive) {
    this->alive = isAlive;
}

float Entity::getX() const {
    return x;
}

float Entity::getY() const {
    return y;
}

float Entity::width() const {
    return am.width();
}

float Entity::height() const {
    return am.height();
}

void Entity::draw(sf::RenderWindow &window) {
    am.draw(window, getX(), getY());
}

bool Entity::intersects(const Entity &other) const {
    // Починить
    return am.getRect().intersects(other.am.getRect());
}

bool Entity::isAlive() const {
    return alive;
}

float Entity::getDx() const {
    return dx;
}

float Entity::getDy() const {
    return dy;
}

void Entity::increaseDx(float value) {
    dx += value;
}

void Entity::increaseDy(float value) {
    dy += value;
}

void Entity::setDx(float acceleration) {
    this->dx = acceleration;
}

void Entity::setDy(float acceleration) {
    this->dy = acceleration;
}

Entity::Entity(AnimationManager &am, float x, float y) : am(am), x(x), y(y) {}
