#ifndef OOP_RGZ_ANIMATIONMANAGER_H
#define OOP_RGZ_ANIMATIONMANAGER_H

#include "Animation.h"

class AnimationManager {
private:
    std::string currentAnimationName;
    std::map<std::string, Animation> animations;
public:
    AnimationManager()= default;

    void create(const std::string& name, Animation animation);

    void draw(sf::RenderWindow &window, float x = 0, float y = 0);

    void set(const std::string& name);

    void flip();

    void tick(float time);

    float width() const;

    float height () const;

    const sf::IntRect& getRect() const {
        return animations.at(currentAnimationName).getRect();
    }

    void pause();

    void play();
};

#endif //OOP_RGZ_ANIMATIONMANAGER_H
