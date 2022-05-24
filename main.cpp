#include "headers/Game/Game.h"
#include "headers/Settings.h"

int main() {
    sf::RenderWindow window(
            sf::VideoMode(SETTINGS.game.window.width, SETTINGS.game.window.height),
            SETTINGS.game.name
            );

    auto map = Map::readFromTextFile("../files/map.txt");
    auto game = Game(map);

    sf::Clock clock;

    while (window.isOpen()) {
        float time = float(clock.getElapsedTime().asMicroseconds()) / 800;
        clock.restart();

        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else
                game.processEvent(event);
        }

        game.update(time);

        window.clear(sf::Color::White);
        game.draw(window);
        window.display();
    }

}