#ifndef OOP_RGZ_GAME_H
#define OOP_RGZ_GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Player/Player.h"
#include "../Level/Level.h"
#include "../Settings.h"

class Game {
private:
    bool running {true};
    bool finished {false};
    Player player;
    Map &map;

    static Game* instance;

    static const std::string PLAYER_TEXTURE_FILE;
public:
    explicit Game(Map & map);

    static Game &getInstance() ;

    void processEvent(const sf::Event &event);

    void draw(sf::RenderWindow &window);

    void update(float time);

    bool isRunning() const;

    void start();

    void pause();

    void finish();

    bool isFinished() const;
private:
    // Возвращает true, если key - цифрa
    static bool isNum(const sf::Keyboard::Key &key);
};

#endif //OOP_RGZ_GAME_H
