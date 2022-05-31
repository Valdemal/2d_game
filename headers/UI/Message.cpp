#include "Message.h"

const sf::Font Message::STANDARD_FONT = []() {
    sf::Font font;
    font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf");
    return font;
}();

Message::Message(const std::string &text, size_t characterSize, float x, float y, bool isActive)
        : sf::Text(text, STANDARD_FONT, characterSize), active(isActive) {

    setPosition(x, y);
    setFillColor(sf::Color::Black);
}

void Message::setColor(sf::Color color) {
    setFillColor(color);
}

void Message::activate() {
    active = true;
}

void Message::deactivate() {
    active = false;
}

bool Message::isActive() const {
    return active;
}

TemporaryMessage::TemporaryMessage(const std::string &text, size_t characterSize, float lifeTimeSec, float x, float y)
        : Message(text, characterSize, x, y, true), lifeTimeSec(lifeTimeSec) {
    clock = sf::Clock();
}

bool TemporaryMessage::isActive() const {

    return clock.getElapsedTime().asSeconds() < lifeTimeSec;
}
