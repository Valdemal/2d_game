#ifndef NIBBLES_01_SETTINGS_H
#define NIBBLES_01_SETTINGS_H


struct settingsT {

    struct {
        const std::string name = "My game";

        struct {
            const size_t width = 1000;
            const size_t height = 350;
        } window;
    } game;

    const size_t TILE_SIZE = 32;
};

static const settingsT SETTINGS = settingsT {};

#endif //NIBBLES_01_SETTINGS_H
