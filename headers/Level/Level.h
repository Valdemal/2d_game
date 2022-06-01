#ifndef OOP_RGZ_LEVEL_H
#define OOP_RGZ_LEVEL_H

#include "entityFactory.hpp"

class Level {
public:
    Level(Player& player, const Map& map);

    Player& getPlayer();

    void addEntity(const entityPtr& entity);

    void draw(sf::RenderWindow &window);

    void update(float time);

private:
    Map map;
    Player player;
    std::vector<entityPtr> entities;

    void parseMap(const Map &map);
    void resolveCollisionsBetweenEntities();
};


#endif //OOP_RGZ_LEVEL_H
