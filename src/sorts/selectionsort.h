//
// Created by Malaya Shekhar on 12/07/24.
//


#pragma once

#include <SFML/Graphics.hpp>
#include "../column_manager.h"

class SelectionSort {
public:
    SelectionSort(ColumnManager *columnManager);
    void sort();

private:
    void SSORT();
    ColumnManager *columnManager;
};
