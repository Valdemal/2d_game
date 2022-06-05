#include "Animation.h"

// Нужно передвавать тектуру по значению и хранить
Animation::Animation(const sf::Texture &t, sf::IntRect size, int count, float speed, int step)
        : speed(speed) {
    sprite.setTexture(t);

    for (int i = 0; i < count; ++i) {
        frames.emplace_back(size.left + i * step, size.top, size.width, size.height);
        flippedFrames.emplace_back(size.left + i * step, size.top, -size.width, size.height);
    }
}

sf::Sprite &Animation::getSprite() {
    return sprite;
}

void Animation::setPlayingStatus(bool playing) {
    this->isPlaying = playing;
}

void Animation::flip() {
    isFlipped = not isFlipped;
}

void Animation::tick(float time) {
    if (not isPlaying)
        return;

    currentFrame += speed * time;

    if (currentFrame >= frames.size())
        currentFrame = 0;

    int i = int(currentFrame);
    if (isFlipped)
        sprite.setTextureRect(flippedFrames[i]);
    else
        sprite.setTextureRect(frames[i]);
}

const sf::Sprite &Animation::getSprite() const {
    return sprite;
}

float Animation::width() const {
    return frames[int(currentFrame)].width;
}

float Animation::height() const {
    return frames[int(currentFrame)].height;
}

