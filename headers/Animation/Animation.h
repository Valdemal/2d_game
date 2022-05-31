#ifndef OOP_RGZ_ANIMATION_H
#define OOP_RGZ_ANIMATION_H

#include <SFML/Graphics.hpp>
#include <utility>
#include <memory>

class Animation {
private:
    std::vector<sf::IntRect> frames, flippedFrames;
    float currentFrame{0};
    float speed;
    bool isFlipped{false}, isPlaying{true};
    sf::Sprite sprite;
public:
    Animation() =default;

    Animation(const sf::Texture &t, sf::IntRect size, int count, float speed, int step);

    sf::Sprite & getSprite();

    const sf::Sprite& getSprite() const {
        return sprite;
    }

    float width() const {
        return frames[int(currentFrame)].width;
    }

    float height() const {
        return frames[int(currentFrame)].height;
    }

    const sf::IntRect& getRect() const{
        return frames[int(currentFrame)];
    }

    void setPlayingStatus(bool isPlaying);

    void flip();

    void tick(float time);
};
#endif //OOP_RGZ_ANIMATION_H
