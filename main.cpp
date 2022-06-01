#include "headers/Controller/Controller.h"

int main() {
    sf::RenderWindow window(
            sf::VideoMode(settings::game::window::WIDTH, settings::game::window::HEIGHT),
            settings::game::name
    );

    Controller controller;

    sf::Clock clock;
    while (window.isOpen()) {
        float time = float(clock.getElapsedTime().asMicroseconds()) / 800;
        clock.restart();

        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else
                controller.processEvent(event);
        }

        controller.update(time);
        window.clear(sf::Color::Green);
        controller.draw(window);
        window.display();
    }

}