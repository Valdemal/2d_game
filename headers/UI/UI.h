#ifndef OOP_RGZ_UI_H
#define OOP_RGZ_UI_H

#include <map>
#include <list>
#include "Message.h"

class UI {
public:
    void add(const std::string& messageName, const Message& message);

    void show(const TemporaryMessage& message);

    Message& getMessage(const std::string& messageName);

    void draw(sf::RenderWindow& window);
private:
    std::map<std::string, Message> messages;
    std::list<TemporaryMessage> tempMessages;
};

#endif //OOP_RGZ_UI_H
