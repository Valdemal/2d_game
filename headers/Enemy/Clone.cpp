#include "Clone.h"
#include "../Level/Level.h"

void Clone::attack(Player &player) {
    player.damage(DAMAGE);
}

Clone::Clone(float x, float y) {
    auto& player = Level::getInstance()->getPlayer();

    setPos(x, y);

    setMaxHp(player->getMaxHp());
    setHp(player->getHp());

    setAnimationManager(player->getAnimationManager());
    getAnimationManager().set("stay");

    // Не работает корректно
    setXDirection(player->getXDirection() == LEFT ? RIGHT : LEFT);
}