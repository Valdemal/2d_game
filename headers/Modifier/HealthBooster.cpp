#include "HealthBooster.h"
#include "../Settings.h"

void HealthBooster::useOn(Player &player) {
    player.heal(HEALTH_BOOST_VALUE);
    setAlive(false);
}

HealthBooster::HealthBooster(float x, float y) {
    setPos(x, y);
    setAnimationManager(settings::healthBooster::STANDARD_AM);
    getAnimationManager().set("stand");
}
