#ifndef OOP_RGZ_ANIMATION_H
#define OOP_RGZ_ANIMATION_H

#include <SFML/Graphics.hpp>
#include <utility>

class Animation {
private:
    std::vector<sf::IntRect> frames, flippedFrames;
    float currentFrame{0}, speed;
    bool isFlipped{false}, isPlaying{true};
    sf::Sprite sprite;
public:
    Animation(sf::Texture &t, int x, int y, int w, int h, int count, float speed, int step)
    : speed(speed) {
        sprite.setTexture(t);

        for (int i = 0; i < count; ++i) {
            frames.emplace_back(x + i * step, y, w, h);
            flippedFrames.emplace_back(x + i * step, y, -w, h);
        }
    }

    sf::Sprite & getSprite(){
        return sprite;
    }

    void setPlayingStatus(bool isPlaying){
        this->isPlaying = isPlaying;
    }

    void flip(){
        isFlipped = not isFlipped;
    }
    
    void tick(float time){
        if (not isPlaying)
            return;

        currentFrame += speed * time;

        if (currentFrame > frames.size())
            currentFrame -= frames.size();

        int i = int(currentFrame);
        if (isFlipped)
            sprite.setTextureRect(flippedFrames[i]);
        else
            sprite.setTextureRect(frames[i]);
    }
};

class AnimationManager {
private:
    std::string currentAnimationName;
    std::map<std::string, Animation> animations;
public:
    AnimationManager()= default;

    void create(const std::string& name, Animation animation){
        animations[name] = std::move(animation);
        currentAnimationName = name;
    }
    
    void draw(sf::RenderWindow &window, int x = 0, int y = 0){
        sf::Sprite &sprite = animations[currentAnimationName].getSprite();
        sprite.setPosition(x, y);
        window.draw(sprite);
    }

    void set(const std::string& name){
        currentAnimationName = name;
    }

    void flip(){
        animations[currentAnimationName].flip();
    }

    void tick(float time){
        animations[currentAnimationName].tick(time);
    }

    void pause(){
        animations[currentAnimationName].setPlayingStatus(false);
    }

    void play(){
        animations[currentAnimationName].setPlayingStatus(true);
    }
};


#endif //OOP_RGZ_ANIMATION_H
