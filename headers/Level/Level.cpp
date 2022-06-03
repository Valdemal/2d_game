#include "Level.h"
#include "../Bullet/Bullet.h"

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
        if ((*it)->isAlive()) {
            resolveCollisionsForEntity(**it);
            it++;
        } else
            it = entities.erase(it);
    }
}

void Level::resolveCollisionsForEntity(Entity &entity) {
    if (entity.type() == "Bullet") {
        auto bullet = dynamic_cast<Bullet &>(entity);

        for (auto &other : entities)
            if (other->type() == "Enemy" and bullet.intersects(*other)) {
                bullet.damageTo(dynamic_cast<Enemy &>(*other));
                bullet.setAlive(false);
                std::cout << "Bullet hit to!";
            }

    } else if (entity.type() == "Enemy" and entity.intersects(*player)) {
        auto enemy = dynamic_cast<Enemy *>(&entity);
        enemy->attack(*player);
    } else if (entity.type() == "Modifier" and entity.intersects(*player)) {
        auto modifier = dynamic_cast<Modifier *>(&entity);
        modifier->useOn(*player);
    }
}

Player &Level::getPlayer() {
    return *player;
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

Level::Level(std::shared_ptr<Player> player, const Map &map) : player(std::move(player)), map(map) {
    if (instance == nullptr) {
        parseMap();
        instance = this;
    } else
        throw std::runtime_error("Trying to redefine singleton!");
}

Level &Level::getInstance() {
    return *instance;
}

const Map &Level::getMap() const {
    return map;
}
