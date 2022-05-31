//
// Created by Vovan on 24.05.2022.
//

#include "Entity.h"

void Entity::setPos(float x, float y) {
    this->x = x;
    this->y = y;
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
    return am.getRect().intersects(other.am.getRect());
}
