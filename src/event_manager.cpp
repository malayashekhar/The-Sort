//
// Created by Malaya Shekhar on 12/07/24.
//

#include "event_manager.h"

EventManager::EventManager(WindowManager *windowManager) {
    this->windowManager = windowManager;
}

void EventManager::update() {
    sf::Event event;
    while(windowManager->getRenderWindow()->pollEvent(event)){
        if(event.type == sf::Event::Closed) {
            std::exit(1);
        }
        else if(event.type == sf::Event::Resized){
            if (windowManager->getSize().x < 400 || windowManager->getSize().y < 250)
                windowManager->setSize(400, 250);
        }
    }
}
