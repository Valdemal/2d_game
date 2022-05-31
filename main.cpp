#include "headers/Game/Game.h"

int main() {
    sf::RenderWindow window(
            sf::VideoMode(settings::game::window::WIDTH, settings::game::window::HEIGHT),
            settings::game::name
    );

    auto map = Map::readFromTextFile("../files/map.txt");

    Player player(settings::PLAYER_AM, 100,
                  float (settings::game::window::WIDTH) / 2 - 60,
                  float (settings::game::window::HEIGHT) / 2);

    Game game (map, player);
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

        window.clear(sf::Color::Green);
        game.draw(window);
        window.display();
    }

}