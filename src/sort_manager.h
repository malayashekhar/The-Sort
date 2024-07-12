//
// Created by Malaya Shekhar on 12/07/24.
//

#pragma once

#include <string>

#include "column_manager.h"
#include "window_manager.h"

#include "./sorts/quicksort.h"
#include "./sorts/bubblesort.h"
#include "./sorts/insertionsort.h"
#include "./sorts/selectionsort.h"
#include "./sorts/mergesort.h"
#include "./sorts/radixsort.h"

class SortManager {
public:
    SortManager(WindowManager *windowManager, ColumnManager *columnManager);

    void sort();

    void setSortType(int sortType);
    int getSortType();
    std::string getTitle();

    void setSorted(bool sorted);
    bool isSorted();

private:
    int sortType;
    bool sorted;

    ColumnManager *columnManager;
    WindowManager *windowManager;
};