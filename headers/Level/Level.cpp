#include "Level.h"

#include <utility>

Level *Level::instance = nullptr;

void Level::update(float time) {
    player->update(time);

    for (const auto &entity : entities)
        entity->update(time);

    resolveCollisionsBetweenEntities();
}

void Level::parseMap() {
    for (size_t i = 0; i < map.rows(); ++i) {
        for (size_t j = 0; j < map.cols(); ++j) {
            if (Map::isEntity(map[i][j]))
                addEntity(EntityFactory::create(map[i][j],
                                                float(j - 1) * settings::TILE_SIZE,
                                                float(i - 1) * settings::TILE_SIZE));
        }
    }
}

void Level::resolveCollisionsBetweenEntities() {
    for (auto it = entities.begin(); it != entities.end();) {
        resolveCollisionsForEntity(**it);

        if ((*it)->isAlive())
            it++;
        else
            it = entities.erase(it);
    }
}

void Level::resolveCollisionsForEntity(Entity &entity) {
    if (entity.type() == "Bullet") {
        auto bullet = dynamic_cast<Bullet *>(&entity);

        for (auto &other : entities)
            if (other->type() == "Enemy" and bullet->intersects(*other))
                bullet->damageTo(dynamic_cast<Enemy &>(*other));

    } else if (entity.type() == "Enemy" and entity.intersects(*player)) {

        auto enemy = dynamic_cast<Enemy *>(&entity);
        enemy->attack(*player);

    } else if (entity.type() == "Modifier" and entity.intersects(*player)) {

        auto modifier = dynamic_cast<Modifier *>(&entity);
        modifier->useOn(*player);

    }
}

const std::unique_ptr<Player>& Level::getPlayer() {
    return player;
}

void Level::addEntity(const entityPtr &entity) {
    entities.push_back(entity);
}

void Level::draw(sf::RenderWindow &window) {
    map.draw(window);
    player->draw(window);

    for (auto &entity : entities) {
        entity->draw(window);
    }
}

Level::Level(std::unique_ptr<Player> player, const Map &map) : player(std::move(player)), map(map) {
    if (instance == nullptr) {
        instance = this;
        parseMap();
    } else
        throw std::runtime_error("Trying to redefine singleton!");
}

Level *Level::getInstance() {
    return instance;
}

const Map &Level::getMap() const {
    return map;
}
