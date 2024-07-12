//
// Created by Malaya Shekhar on 12/07/24.
//

#include "column_manager.h"

ColumnManager::ColumnManager(int columns_number, WindowManager *windowManager, EventManager *eventManager) {
    this->windowManager = windowManager;
    this->eventManager = eventManager;
    this->columns_number = columns_number;
    this->width = (windowManager->getSize().x * 1.0) / (this->columns_number * 1.0);
    this->original_window_height = windowManager->getInitialSize().y;
}

std::vector<sf::RectangleShape> ColumnManager::getColumns() {
    return columns;
}

int ColumnManager::getValue(int index) {
    return columns[index].getSize().y;
}

int ColumnManager::getValueR(int index) {
    highlight(index);
    return columns[index].getSize().y;
}

void ColumnManager::setValue(int index, int value) {
    columns[index].setSize(sf::Vector2f(width, value));
    columns[index].setPosition(0, windowManager->getRenderWindow()->getSize().y - value);
    columns[index].setFillColor(getColor(value));
}

int ColumnManager::getNumber() {
    return columns_number;
}

void ColumnManager::swap(int index1, int index2) {
    std::iter_swap(columns.begin() + index1, columns.begin() + index2);
}

void ColumnManager::highlight(int index1, int index2) {
    sf::Color color_index1 = columns[index1].getFillColor();
    sf::Color color_index2 = columns[index2].getFillColor();
    columns[index1].setFillColor(sf::Color::White);
    columns[index2].setFillColor(sf::Color::White);
    render();
    eventManager->update();
    columns[index1].setFillColor(color_index1);
    columns[index2].setFillColor(color_index2);
}

void ColumnManager::highlight(int index) {
    sf::Color color = columns[index].getFillColor();
    columns[index].setFillColor(sf::Color::White);
    render();
    eventManager->update();
    columns[index].setFillColor(color);
}

void ColumnManager::render() {
    windowManager->clearWindow();
    for(int i = 0; i < columns_number; i++){
        double posX = this->width * i;
        columns[i].setPosition(posX, original_window_height - columns[i].getSize().y);
        windowManager->render(columns[i]);
    }
    windowManager->displayWindow();
}


sf::Color ColumnManager::getColor(int height) {
    float max_height = float(original_window_height);
    float hue_shift = float(255 / max_height);
    float hue_increase = hue_shift * height;
    float hue_decrease = 255 - hue_increase;
    switch(sortType) {
        case 0:
            // Purple -> Yellow
            return sf::Color(255, hue_decrease, hue_increase);

        case 1:
            // Red -> Purple
            return sf::Color(255, 0, hue_increase);

        case 2:
            // Red -> Yellow
            return sf::Color(255, hue_increase, 0);

        case 3:
            // Green -> Yellow
            return sf::Color(hue_increase, 255, 0);

        case 4:
            // Blue -> Purple
            return sf::Color(hue_increase, hue_decrease, 255);

        case 5:
            // Cyan -> Red
            return sf::Color(hue_increase, hue_decrease, hue_decrease);

        default:
            // Red if it fails
            return sf::Color::Red;
    }
}

void ColumnManager::generate(int sortType) {
    columns.clear();
    this->sortType = sortType;
    create();
    shuffle();
}

void ColumnManager::create() {
    for (int i = 0; i < columns_number; i++) {
        sf::RectangleShape column;
        columns.push_back(column);
        double ratio = (original_window_height * 1.0) / (columns_number * 1.0);
        double height = ratio * (i+1);
        columns[i].setSize(sf::Vector2f(this->width, height));
        columns[i].setPosition(0, original_window_height - height);
        if(this->width > 10) {
            columns[i].setOutlineThickness(1);
            columns[i].setOutlineColor(sf::Color::Black);
        }
        columns[i].setFillColor(getColor(height));
    }
}

void ColumnManager::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(columns.begin(), columns.end(), g);
}
