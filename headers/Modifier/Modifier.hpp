#ifndef OOP_RGZ_MODIFIER_HPP
#define OOP_RGZ_MODIFIER_HPP

#include <utility>
#include "../Player/Player.h"

class Modifier : public Entity {
public:
    Modifier()=default;

    virtual void useOn(Player& player) = 0;

    std::string type() const final {
        return "Modifier";
    }
};

#endif //OOP_RGZ_MODIFIER_HPP
