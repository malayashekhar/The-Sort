//
// Created by Malaya Shekhar on 12/07/24.
//

#include "bubblesort.h"

BubbleSort::BubbleSort(ColumnManager *columnManager) {
    this->columnManager = columnManager;
}

void BubbleSort::sort() {
    BSORT();
}

void BubbleSort::BSORT() {
    for(int i = 0; i < columnManager->getNumber(); i++) {
        for(int j = 0; j < (columnManager->getNumber() - i) - 1; j++) {
            double currentValue = columnManager->getValue(j);
            double nextValue = columnManager->getValue(j+1);
            columnManager->highlight(j, j+1);
            if(nextValue < currentValue)    columnManager->swap(j, j+1);
        }
    }
}

