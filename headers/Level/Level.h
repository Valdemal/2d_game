#ifndef OOP_RGZ_LEVEL_H
#define OOP_RGZ_LEVEL_H

#include <list>
#include "entityFactory.hpp"

class Level {
public:
    static void create(std::unique_ptr<Player> player, const Map& map);

    static Level *const getInstance();

    Level()=delete;

    Level(const Level &)=delete;

    const std::unique_ptr<Player> & getPlayer();

    const Map& getMap() const;

    void addEntity(const entityPtr& entity);

    void draw(sf::RenderWindow &window);

    void update(float time);
private:
    static Level* instance;

    Map map{};
    std::unique_ptr<Player> player;
    std::list<entityPtr> entities;

    explicit Level(std::unique_ptr<Player> player);
    void parseMap(const Map &m);
    void resolveCollisionsBetweenEntities();
    void resolveCollisionsForEntity(Entity &entity);
};


#endif //OOP_RGZ_LEVEL_H
