#ifndef OOP_RGZ_HEALTHBOOSTER_HPP
#define OOP_RGZ_HEALTHBOOSTER_HPP

#include "Modifier.hpp"

class HealthBooster : public Modifier {
private:
    static const size_t HEALTH_BOOST_VALUE = 25;
public:
    HealthBooster(float x, float y) {
        setPos(x, y);
        am = createHealthBoosterAnim();
        am.set("stand");
    }

    void useOn(Player& player) override {
        player.heal(HEALTH_BOOST_VALUE);
        setAlive(false);
    }
private:
    AnimationManager createHealthBoosterAnim(){
        AnimationManager am;
        sf::Texture t;
        // Заменить
        t.loadFromFile("../files/1.png");
        am.create("stand", Animation(t, sf::IntRect(10, 10, 30, 30), 1, 0,0));
        return am;
    }
};


#endif //OOP_RGZ_HEALTHBOOSTER_HPP
