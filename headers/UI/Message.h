#ifndef OOP_RGZ_MESSAGE_H
#define OOP_RGZ_MESSAGE_H

#include <SFML/Graphics.hpp>

class Message : public sf::Text {
private:
    bool active{};

    static const sf::Font STANDARD_FONT;
public:
    Message() = default;

    Message(const std::string &text, size_t characterSize, float x = 0, float y = 0, bool isActive = false);

    void setColor(sf::Color color);

    void activate();

    void deactivate();

    virtual bool isActive() const;
};

class TemporaryMessage : public Message {
private:
    sf::Clock clock;
    float lifeTimeSec;
public:
    TemporaryMessage(const std::string &text, size_t characterSize, float lifeTimeSec, float x = 0, float y = 0);

    bool isActive() const override;
};

#endif //OOP_RGZ_MESSAGE_H
