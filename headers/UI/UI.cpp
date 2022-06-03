#include "UI.h"


void UI::add(const std::string &messageName, const Message &message) {
    messages[messageName] = message;
}

void UI::show(const TemporaryMessage &message) {
    tempMessages.push_back(message);
}

Message &UI::getMessage(const std::string &messageName) {
    return messages[messageName];
}

void UI::draw(sf::RenderWindow &window) {
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