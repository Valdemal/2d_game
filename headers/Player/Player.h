#ifndef OOP_RGZ_PLAYER_H
#define OOP_RGZ_PLAYER_H

#include <SFML/Graphics.hpp>
#include "../Level/Level.h"
//#include "../Game/Game.h"

class Player {
private:
    sf::Sprite sprite;
    sf::FloatRect rect;
    float currentFrame{};
    float dx{0}, dy{0};
    bool onGround{};


    constexpr static const double ACCELERATION = 10;
public:
    Player() = default;

    explicit Player(sf::Texture &image,
                    sf::FloatRect textureRect,
                    std::pair<float, float> position);

    void moveLeft();

    void moveRight();

    void update(float time, const Map &map);

    void draw(sf::RenderWindow &window);

    void jump();

    void resolveCollisions(const Map &map, bool isHorizontalDirection);

private:
//    void resolveCollisions()
};


#endif //OOP_RGZ_PLAYER_H
