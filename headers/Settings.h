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

        AnimationManager getStandardAM();

        const AnimationManager STANDARD_AM = [](){
            sf::Texture t;
            t.loadFromFile(settings::player::TEXTURE_FILE);

            AnimationManager am;
            am.add("walk",
                   Animation(t,
                             sf::IntRect(0, 244, 40, 50),
                             6, 0.005, 40));

            am.add("jump", Animation(t, sf::IntRect(0, 528, 29, 30), 4, 0.0045, 40));
            am.add("stay", Animation(t, sf::IntRect(0, 187, 42, 52), 3, 0.002, 40));
            return am;
        }();
    }

    namespace bullet {
        static const char *const TEXTURE_FILE = "../files/Bullet.png";

        AnimationManager getStandardAm();
    }

    namespace map {
        static const char *const FILE = "../files/map.txt";
    }
    const sf::Texture PLAYER_TEXTURE = [](){
        sf::Texture t;
        t.loadFromFile(settings::player::TEXTURE_FILE);
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
