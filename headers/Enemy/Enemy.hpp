#ifndef OOP_RGZ_ENEMY_HPP
#define OOP_RGZ_ENEMY_HPP

#include "../Player/Player.h"

class Enemy : public Character {
public:
    Enemy()=default;


    std::string type() const {
        return "Enemy";
    }//    virtual void attack(Player& player) = 0;
};


#endif //OOP_RGZ_ENEMY_HPP
