#ifndef OOP_RGZ_MODIFIER_HPP
#define OOP_RGZ_MODIFIER_HPP

#include <utility>
#include "../Entity/Character.h"

class Modifier : public Entity {
public:
    Modifier()=default;

    virtual void useOn(Character& player) = 0;

    virtual void update(float time) override{
        am.tick(time);
    }

    std::string type() const override {
        return "Modifier";
    }
};

#endif //OOP_RGZ_MODIFIER_HPP