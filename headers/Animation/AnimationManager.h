#ifndef OOP_RGZ_ANIMATIONMANAGER_H
#define OOP_RGZ_ANIMATIONMANAGER_H

#include "Animation.h"

class AnimationManager {
public:
    AnimationManager()= default;

    void add(const std::string& name, Animation animation);

    void draw(sf::RenderWindow &window, float x = 0, float y = 0);

    void set(const std::string& name);

    void flip();

    void tick(float time);

    float width() const;

    float height () const;

    void pause();

    void play();
private:
    std::string currentAnimationName;
    std::map<std::string, Animation> animations;
};

#endif //OOP_RGZ_ANIMATIONMANAGER_H
