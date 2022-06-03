#ifndef OOP_RGZ_ANIMATION_H
#define OOP_RGZ_ANIMATION_H

#include <SFML/Graphics.hpp>
#include <utility>
#include <memory>

class Animation {
public:
    Animation() =default;

    Animation(const sf::Texture &t, sf::IntRect size, int count, float speed, int step);

    sf::Sprite & getSprite();

    const sf::Sprite& getSprite() const;

    float width() const;

    float height() const;

    void setPlayingStatus(bool isPlaying);

    void flip();

    void tick(float time);
private:
    std::vector<sf::IntRect> frames, flippedFrames;
    float currentFrame{0};
    float speed{0};
    bool isFlipped{false}, isPlaying{true};
    sf::Sprite sprite;
};
#endif //OOP_RGZ_ANIMATION_H
