//
// Created by Malaya Shekhar on 12/07/24.
//

#include "selectionsort.h"

SelectionSort::SelectionSort(ColumnManager *columnManager) {
    this->columnManager = columnManager;
}

void SelectionSort::sort() {
    SSORT();
}

void SelectionSort::SSORT() {
    for(int i = 0; i < columnManager->getNumber(); i++){
        double currentMinimum = columnManager->getValue(i);
        int currentMinimumIndex = i;
        for(int j = i+1; j < columnManager->getNumber(); j++){
            double currentValue = columnManager->getValue(j);
            columnManager->highlight(j, currentMinimumIndex);
            if(currentValue < currentMinimum) {
                currentMinimum = currentValue;
                currentMinimumIndex = j;
            }
        }
        columnManager->swap(i, currentMinimumIndex);
    }
}

