#ifndef OOP_RGZ_UI_HPP
#define OOP_RGZ_UI_HPP

#include <map>
#include <list>
#include "Message.h"

class UI {
private:
    std::map<std::string, Message> messages;
    std::list<TemporaryMessage> tempMessages;
public:
    void add(const std::string& messageName, const Message& message){
        messages[messageName] = message;
    }

    void show(const TemporaryMessage& message){
        tempMessages.push_back(message);
    }

    Message& getMessage(const std::string& messageName) {
        return messages[messageName];
    }

    void draw(sf::RenderWindow& window) {
        for (auto it = tempMessages.begin(); it != tempMessages.end();)
            if(it->isActive()){
                window.draw(*it);
                it++;
            } else
                it = tempMessages.erase(it);

        for (const auto& message: messages)
            if (message.second.isActive()){
                window.draw(message.second);
            }
    }
};


#endif //OOP_RGZ_UI_HPP
