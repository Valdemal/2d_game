#include "Level.h"

void Level::update(float time) {
    player.update(time);

    for (const auto &entity : entities)
        entity->update(time);

    resolveCollisionsBetweenEntities();
}


void Level::parseMap(const Map &map) {
    for (size_t i = 0; i < map.rows(); ++i) {
        for (size_t j = 0; j < map.cols(); ++j) {
            if (map[i][j] != mapObject::Empty && map[i][j] != mapObject::Border)
                addEntity(EntityFactory::create(map[i][j],
                                                float(j - 1) * settings::TILE_SIZE,
                                                float(i - 1) * settings::TILE_SIZE));
        }
    }
}

void Level::resolveCollisionsBetweenEntities() {

    for (auto it = entities.begin(); it != entities.end();) {
        if ((*it)->isAlive()) {

            if ((*it)->type() == "Bullet") {
                auto bullet = dynamic_cast<Bullet &>(**it);

                for (auto &entity : entities)
                    if (entity->type() == "Enemy" and bullet.intersects(*entity)) {
                        bullet.damageTo(dynamic_cast<Enemy &>(*entity));
                        bullet.setAlive(false);
                        std::cout << "Bullet hit to!";
                    }

            } else if ((*it)->type() == "Enemy" and (*it)->intersects(player)) {
                auto enemy = dynamic_cast<Enemy*>(it->get());
                std::cout << "Enemy should attack player" << std::endl;
                // Тут логика атаки, которая пока не работает по странным причинам

            } else if ((*it)->type() == "Modifier" and (*it)->intersects(player)) {
                std::cout << "Modify";
                auto modifier = dynamic_cast<Modifier*>(it->get());
                modifier->useOn(player);
            }

            it++;
        } else
            it = entities.erase(it);
    }
}

Player &Level::getPlayer() {
    return player;
}

void Level::addEntity(const entityPtr &entity) {
    entities.push_back(entity);
}

void Level::draw(sf::RenderWindow &window) {
    map.draw(window);
    player.draw(window);

    for (auto &entity : entities) {
        entity->draw(window);
    }
}

Level::Level(Player &player, const Map &map) : player(player), map(map) {
    parseMap(map);
}
