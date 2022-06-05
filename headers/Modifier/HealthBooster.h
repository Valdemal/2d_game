#ifndef OOP_RGZ_HEALTHBOOSTER_H
#define OOP_RGZ_HEALTHBOOSTER_H

#include "Modifier.hpp"

class HealthBooster : public Modifier {
public:
    HealthBooster(float x, float y);

    void useOn(Player& player) override;
private:
    static const size_t HEALTH_BOOST_VALUE = 25;
};

#endif //OOP_RGZ_HEALTHBOOSTER_H
