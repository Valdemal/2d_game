#ifndef NIBBLES_01_SETTINGS_H
#define NIBBLES_01_SETTINGS_H

#include <SFML/Graphics.hpp>
#include "Animation/AnimationManager.h"

namespace settings {

    namespace game {
        const std::string name = "My game";

        namespace window {
            const size_t WIDTH = 1000;
            const size_t HEIGHT = 350;
        }
    }

    const size_t TILE_SIZE = 32;

    const std::string PLAYER_TEXTURE_FILE = "../files/fang.png";

    const sf::Texture PLAYER_TEXTURE = [](){
        sf::Texture t;
        t.loadFromFile(settings::PLAYER_TEXTURE_FILE);
        return t;
    }();

    const AnimationManager PLAYER_AM = [](){
        AnimationManager am;
        am.add("walk",
               Animation(settings::PLAYER_TEXTURE,
                         sf::IntRect(0, 244, 40, 50),
                         6, 0.005, 40));

        am.add("jump", Animation(settings::PLAYER_TEXTURE, sf::IntRect(0, 528, 29, 30), 4, 0.0045, 40));
        am.add("stay", Animation(settings::PLAYER_TEXTURE, sf::IntRect(0, 187, 42, 52), 3, 0.002, 40));
        return am;
    }();
}

#endif //NIBBLES_01_SETTINGS_H
