#include "AnimationManager.h"

void AnimationManager::add(const std::string &name, Animation animation) {
    animations[name] = std::move(animation);
    currentAnimationName = name;
}

void AnimationManager::draw(sf::RenderWindow &window, float x, float y) {
    animations[currentAnimationName].getSprite().setPosition(x, y);
    window.draw(animations[currentAnimationName].getSprite());
}

void AnimationManager::set(const std::string &name) {
    if (not animations.count(name))
        throw std::runtime_error("Animation manager has no " + name + " animation!");

    currentAnimationName = name;
}

void AnimationManager::flip() {
    for (auto &animation : animations)
        animation.second.flip();
}

void AnimationManager::tick(float time) {
    animations[currentAnimationName].tick(time);
}

void AnimationManager::pause() {
    animations[currentAnimationName].setPlayingStatus(false);
}

void AnimationManager::play() {
    animations[currentAnimationName].setPlayingStatus(true);
}

float AnimationManager::width() const {
    return animations.at(currentAnimationName).width();
}

float AnimationManager::height() const {
    return animations.at(currentAnimationName).height();
}

