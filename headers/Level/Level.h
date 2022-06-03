#ifndef OOP_RGZ_LEVEL_H
#define OOP_RGZ_LEVEL_H

#include "entityFactory.hpp"


class Level {
public:
    Level(std::shared_ptr<Player> player, const Map& map);

    static Level& getInstance();

    Player& getPlayer();

    const Map& getMap() const;

    void addEntity(const entityPtr& entity);

    void draw(sf::RenderWindow &window);

    void update(float time);

private:
    static Level* instance;

    Map map;
    std::shared_ptr<Player> player;
    std::vector<entityPtr> entities;

    void parseMap();
    void resolveCollisionsBetweenEntities();

    void resolveCollisionsForEntity(Entity &entity);
};


#endif //OOP_RGZ_LEVEL_H
