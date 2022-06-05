#ifndef NIBBLES_01_SETTINGS_H
#define NIBBLES_01_SETTINGS_H

#include <SFML/Graphics.hpp>
#include "Animation/AnimationManager.h"

namespace settings {

    static const char *const GAME_NAME = "My game";

    const size_t TILE_SIZE = 32;

    namespace window {
        const size_t WIDTH = 1000;
        const size_t HEIGHT = 350;
    }

    namespace player {
        static const char *const TEXTURE_FILE = "../files/fang.png";

        const sf::Texture TEXTURE = [](){
            sf::Texture t;
            t.loadFromFile(settings::player::TEXTURE_FILE);
            return t;
        }();

        const AnimationManager STANDARD_AM = [](){
            AnimationManager am;
            am.add("walk",
                   Animation(TEXTURE,
                             sf::IntRect(0, 244, 40, 50),
                             6, 0.005, 40));

            am.add("jump", Animation(TEXTURE, sf::IntRect(0, 528, 29, 30), 4, 0.0045, 40));
            am.add("stay", Animation(TEXTURE, sf::IntRect(0, 187, 42, 52), 3, 0.002, 40));
            return am;
        }();
    }

    namespace bullet {
        static const char *const TEXTURE_FILE = "../files/Bullet.png";

        const sf::Texture TEXTURE = [](){
            sf::Texture texture;

            texture.loadFromFile(TEXTURE_FILE);
            return texture;
        }();

        const AnimationManager STANDARD_AM = [](){
            AnimationManager am;
            am.add("move", Animation(TEXTURE, sf::IntRect(0,0,12,12), 1, 0.002,1));
            am.add("explode", Animation(TEXTURE, sf::IntRect(0, 10, 13, 14), 3, 0.002, 10));

            return am;
        }();
    }

    namespace healthBooster {
        static const char* const TEXTURE_FILE = "../files/HealthBooster.png";

        const sf::Texture TEXTURE = [](){
            sf::Texture texture;
            texture.loadFromFile(TEXTURE_FILE);
            return texture;
        }();

        const AnimationManager STANDARD_AM = [](){
            AnimationManager am;

            am.add("stand", Animation(TEXTURE,
                                      sf::IntRect(0,0,15,15),
                                      5, 0.002,15));
            return am;
        }();
    }

    namespace map {
        static const char *const FILE = "../files/map.txt";
    }
}

#endif //NIBBLES_01_SETTINGS_H
