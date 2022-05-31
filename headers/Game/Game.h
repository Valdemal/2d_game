#ifndef OOP_RGZ_GAME_H
#define OOP_RGZ_GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Player/Player.h"
#include "../Settings.h"
#include "../UI/UI.hpp"
#include "entityFactory.hpp"

class Player;

class Game {
public:
    explicit Game(Map &map, Player &player);

    static Game &getInstance();

    const Map& getMap();

    void addEntity(const entityPtr& entity);

    void processEvent(const sf::Event &event);

    void draw(sf::RenderWindow &window);

    void update(float time);

    bool isRunning() const;

    void start();

    void pause();

    void finish();

    bool isFinished() const;
private:
    Player &player;

    Map &map;
    UI ui;

    std::vector<entityPtr> entities;

    bool running {true};
    bool finished {false};

    static Game* instance;

    void parseMap();

    void resolveCollisionsBetweenEntities();
};

#endif //OOP_RGZ_GAME_H
