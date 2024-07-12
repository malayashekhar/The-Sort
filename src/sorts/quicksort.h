//
// Created by Malaya Shekhar on 12/07/24.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "../column_manager.h"

class QuickSort {
public:
    QuickSort(ColumnManager *columnManager);
    void sort();

private:
    void QSORT(int min, int max);
    int partition(int min, int max);
    ColumnManager *columnManager;
};
