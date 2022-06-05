#ifndef OOP_RGZ_CONTROLLER_H
#define OOP_RGZ_CONTROLLER_H

#include <SFML/Graphics.hpp>
#include "../Level/Level.h"
#include "../UI/UI.h"

class Controller {
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

    UI ui;
    bool running{true};
    bool finished{false};

    void showStartMessage();
};


#endif //OOP_RGZ_CONTROLLER_H
