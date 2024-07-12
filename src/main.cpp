//
// Created by Malaya Shekhar on 12/07/24.
//


#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "window_manager.h"
#include "event_manager.h"
#include "column_manager.h"
#include "sort_manager.h"


int main() {

    int COLUMNS_NUMBER = 100;
    srand(time(NULL));

    WindowManager windowManager(1000, 600);
    EventManager eventManager(&windowManager);
    ColumnManager columnManager(COLUMNS_NUMBER, &windowManager, &eventManager);
    SortManager sortManager(&windowManager, &columnManager);

    while(windowManager.isRunning()) {

        sf::Event event;

        while(windowManager.getRenderWindow()->pollEvent(event)) {
            switch(event.type){
                case sf::Event::Closed:
                    windowManager.terminateWindow();
                    break;

                case sf::Event::Resized:
                    if (windowManager.getSize().x < 400 || windowManager.getSize().y < 250)
                        windowManager.setSize(400, 250);
                    break;

                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::S) {
                        columnManager.shuffle();
                        sortManager.setSorted(false);
                    }

                    else if(event.key.code == sf::Keyboard::R) {
                        columnManager.generate(sortManager.getSortType());
                        sortManager.setSorted(false);
                    }

                    else if(event.key.code == sf::Keyboard::Enter) sortManager.sort();

                    else if(event.key.code == sf::Keyboard::Num1) sortManager.setSortType(0);
                    else if(event.key.code == sf::Keyboard::Num2) sortManager.setSortType(1);
                    else if(event.key.code == sf::Keyboard::Num3) sortManager.setSortType(2);
                    else if(event.key.code == sf::Keyboard::Num4) sortManager.setSortType(3);
                    else if(event.key.code == sf::Keyboard::Num5) sortManager.setSortType(4);
                    else if(event.key.code == sf::Keyboard::Num6) sortManager.setSortType(5);
                    break;

                default:
                    break;
            }
        }
        columnManager.render();
    }

    return 0;
}