//
// Created by Malaya Shekhar on 12/07/24.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "../column_manager.h"

class MergeSort {
public:
    MergeSort(ColumnManager *columnManager);
    void sort();

private:
    void MSORT(int low, int high);
    void merge(int low, int high, int mid);
    ColumnManager *columnManager;
};
