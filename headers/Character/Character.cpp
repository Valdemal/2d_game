#include "Character.h"
#include "../Map/Map.h"
#include "../Level/Level.h"

void Character::moveLeft() {
    if (xDirection == RIGHT)
        dirChanged = true;

    xDirection = LEFT;

    if (state == STAY)
        state = WALK;

    setDx(-ACCELERATION);
}

void Character::moveRight() {
    if (xDirection == LEFT)
        dirChanged = true;

    xDirection = RIGHT;

    if (state == STAY)
        state = WALK;

    setDx(ACCELERATION);
}

void Character::jump() {
    if (onGround() and (state == STAY or state == WALK)) {
        setDy(-0.27);
        state = JUMP;
        setOnGround(false);
    }
}

void Character::stop() {
    setDx(0);
    state = STAY;
}

void Character::setAnimationByState() {
    switch (state) {
        case STAY:
            am.set("stay");
            break;
        case WALK:
            am.set("walk");
            break;
        case JUMP:
            am.set("jump");
            break;
    }

    if (dirChanged)
        am.flip();

    dirChanged = false;
}

void Character::update(float time) {
    setAnimationByState();
    setX(getX() + getDx() * time);

    auto map = Level::getInstance().getMap();

    resolveCollisions(map, true);
    if (not onGround()) {
        increaseDy(0.0005f * time);
    }
    setY(getY() + getDy() * time);
    setOnGround(false);
    resolveCollisions(map, false);

    setDx(0);
    am.tick(time);
}


void Character::resolveCollisions(const Map &map, bool isHorizontalDirection) {
    for (size_t i = std::abs(getY() / float(settings::TILE_SIZE)); i < std::abs((getY() + height()) / float(settings::TILE_SIZE)); i++)
        // Происходит телепорт при долгом беге в левую стену
        for (size_t j = std::abs(getX() / float(settings::TILE_SIZE)); j < std::abs((getX() + width()) / float(settings::TILE_SIZE)); j++) {

            // Обработка столкновения с границей
            if (map[i][j] == mapObject::Border) {
                if (isHorizontalDirection) {

                    if (getDx() > 0) {
                        setX(float(j) * settings::TILE_SIZE - width());

                    } else if (getDx() < 0)
                        setX(float(j) * settings::TILE_SIZE + settings::TILE_SIZE);

                } else {

                    if (getDy() > 0) {
                        setY(float(i) * settings::TILE_SIZE - height());
                        setDy(0);
                        setOnGround(true);
                    } else if (getDy() < 0) {
                        setY(float(i) * settings::TILE_SIZE + settings::TILE_SIZE);
                        setDy(0);
                    }

                }
            }
        }
}

Character::Character(AnimationManager &am, size_t maxHp, float x, float y) : Entity(am, x, y), maxHp(maxHp), hp(maxHp) {
    state = STAY;
    xDirection = RIGHT;
}

size_t Character::getHp() const {
    return hp;
}

void Character::setHp(size_t value) {
    this->hp = value;
}

void Character::damage(size_t damage) {
    if (damage >= hp) {
        kill();
    } else
        hp -= damage;
}

void Character::heal(size_t value) {
    if (hp + value > maxHp)
        hp = maxHp;
    else
        hp += value;
}

void Character::heal() {
    hp = maxHp;
}

void Character::kill() {
    hp = 0;
    setAlive(false);
}

void Character::setOnGround(bool onGround) {
    this->isOnGround = onGround;
}

bool Character::onGround() const {
    return isOnGround;
}

