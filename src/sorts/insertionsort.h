//
// Created by Malaya Shekhar on 12/07/24.
//

#pragma once

#include <SFML/Graphics.hpp>

#include "../column_manager.h"

class InsertionSort {
public:
    InsertionSort(ColumnManager *columnManager);
    void sort();

private:
    void ISORT();
    ColumnManager *columnManager;
};
