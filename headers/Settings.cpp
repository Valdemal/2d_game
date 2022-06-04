#include "Settings.h"

AnimationManager settings::player::getStandardAM() {
    sf::Texture texture;
    texture.loadFromFile(settings::player::TEXTURE_FILE);

    AnimationManager am;
    am.add("walk",
           Animation(texture,
                     sf::IntRect(0, 244, 40, 50),
                     6, 0.005, 40));

    am.add("jump",
           Animation(texture,
                     sf::IntRect(0, 528, 29, 30),
                     4, 0.0045, 40));

    am.add("stay",
           Animation(texture,
                     sf::IntRect(0, 187, 42, 52),
                     3, 0.002, 40));

    return am;
}


AnimationManager settings::bullet::getStandardAm() {
    AnimationManager am;
    sf::Texture texture;

    texture.loadFromFile(settings::bullet::TEXTURE_FILE);
    am.add("move", Animation(texture, sf::IntRect(0,0,12,12), 1, 0.1,1));
    am.add("explode", Animation(texture, sf::IntRect(0, 10, 13, 14), 3, 0.5, 2));

    return am;
}