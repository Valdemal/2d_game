#include "headers/Controller/Controller.h"
#include "headers/Bullet/Bullet.h"

int main() {
    sf::RenderWindow window(
            sf::VideoMode(settings::window::WIDTH, settings::window::HEIGHT),
            settings::GAME_NAME
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

        window.clear(sf::Color::White);
        controller.update(time);
        controller.draw(window);
        window.display();
    }

}