#ifndef OOP_RGZ_LEVEL_H
#define OOP_RGZ_LEVEL_H

#include <list>
#include "entityFactory.hpp"
#include "../Bullet/Bullet.h"


class Level {
public:
    Level(std::unique_ptr<Player> player, const Map& map);

    Level()=delete;
    Level(const Level &)=delete;

    static Level *getInstance();

    const std::unique_ptr<Player> & getPlayer();

    const Map& getMap() const;

    void addEntity(const entityPtr& entity);

    void draw(sf::RenderWindow &window);

    void update(float time);
private:
    static Level* instance;

    Map map;
    std::unique_ptr<Player> player;
    std::list<entityPtr> entities;

    void parseMap();
    void resolveCollisionsBetweenEntities();
    void resolveCollisionsForEntity(Entity &entity);
};


#endif //OOP_RGZ_LEVEL_H
