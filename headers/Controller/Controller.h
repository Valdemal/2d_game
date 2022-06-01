#ifndef OOP_RGZ_CONTROLLER_H
#define OOP_RGZ_CONTROLLER_H

#include "../UI/UI.hpp"
#include "../Settings.h"
#include "../Level/Level.h"


class Controller {
/*
Контроллер обеспечивает взимодействие пользователя с программой.
*/
public:
    Controller();

    void processEvent(const sf::Event &event);

    void draw(sf::RenderWindow &window);

    void update(float time);

private:
    bool isRunning() const;

    void start();

    void pause();

    void finish();

    bool isFinished() const;


    std::unique_ptr<Level> level;
    UI ui;
    bool running{true};
    bool finished{false};

};


#endif //OOP_RGZ_CONTROLLER_H
