#include "Entity.h"

Entity::Entity(const AnimationManager &am, float x, float y) : animationManager(am), x(x), y(y) {}


direction_t Entity::getXDirection() const {
    return xDirection;
}

void Entity::setXDirection(direction_t dir) {
    xDirection = dir;
}

AnimationManager &Entity::getAnimationManager() {
    return animationManager;
}

void Entity::setAnimationManager(const AnimationManager &am) {
    animationManager = am;
}

void Entity::update(float time) {
    animationManager.tick(time);
}

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
    return animationManager.width();
}

float Entity::height() const {
    return animationManager.height();
}

void Entity::draw(sf::RenderWindow &window) {
    animationManager.draw(window, getX(), getY());
}

bool Entity::intersects(const Entity &other) const {
    compareRectStruct a {getX(), getY(), getX() + width(), getY() + height()};
    compareRectStruct b {other.getX(), other.getY(), other.getX() + other.width(), other.getY() + other.height()};

    return checkIntersection(a, b);
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

bool Entity::checkIntersection(Entity::compareRectStruct a, Entity::compareRectStruct b) {
    return (
                   (
                           (
                                   (a.x >= b.x && a.x <= b.x1) || (a.x1 >= b.x && a.x1 <= b.x1)
                           ) && (
                                   (a.y >= b.y && a.y <= b.y1) || (a.y1 >= b.y && a.y1 <= b.y1)
                           )
                   ) || (
                           (
                                   (b.x >= a.x && b.x <= a.x1) || (b.x1 >= a.x && b.x1 <= a.x1)
                           ) && (
                                   (b.y >= a.y && b.y <= a.y1) || (b.y1 >= a.y && b.y1 <= a.y1)
                           )
                   )
           ) || (
                   (
                           (
                                   (a.x >= b.x && a.x <= b.x1) || (a.x1 >= b.x && a.x1 <= b.x1)
                           ) && (
                                   (b.y >= a.y && b.y <= a.y1) || (b.y1 >= a.y && b.y1 <= a.y1)
                           )
                   ) || (
                           (
                                   (b.x >= a.x && b.x <= a.x1) || (b.x1 >= a.x && b.x1 <= a.x1)
                           ) && (
                                   (a.y >= b.y && a.y <= b.y1) || (a.y1 >= b.y && a.y1 <= b.y1)
                           )
                   )
           );
}