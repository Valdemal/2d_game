#ifndef OOP_RGZ_BULLET_H
#define OOP_RGZ_BULLET_H

#include "../Entity/Character.h"

class Bullet : public Entity {
private:
    size_t damage;

    const float ACCELERATION = 10;

public:
    Bullet(float x, float y, size_t damage, bool isRightDirection);

    void damageTo(Character &character);

    void update(float time) override;

    std::string type() const final;

private:
    // У всех пуль одна и та же анимация
    static AnimationManager createBulletAnimation() {
        AnimationManager anim;
        sf::Texture t;
        t.loadFromFile(settings::PLAYER_TEXTURE_FILE);
        anim.create("move",Animation(t,sf::IntRect (247,582,8,8),1,0,0));
        anim.create("explode",Animation(t, sf::IntRect(323,583,18,18),4,0.01,29));
        return anim;
    }
};


#endif //OOP_RGZ_BULLET_H
