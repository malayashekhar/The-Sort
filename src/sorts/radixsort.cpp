//
// Created by Malaya Shekhar on 12/07/24.
//

#include "radixsort.h"

RadixSort::RadixSort(ColumnManager *columnManager) {
    this->columnManager = columnManager;
}

void RadixSort::sort() {
    RSORT();
}

void RadixSort::RSORT() {
    int highest_value = 0;
    for(int i = 0; i < columnManager->getNumber(); i++) {
        int value = columnManager->getValue(i);
        if (value > highest_value)  highest_value = value;
    }
    for (int exponent = 1; highest_value / exponent; exponent *= 10) {
        count(exponent);
    }
}

void RadixSort::count(int exponent) {
    int columns_number = columnManager->getNumber();
    int temp[columns_number];
    int count[10] = { 0 };
    for (int i = 0; i < columns_number; i++) {
        int value = columnManager->getValueR(i);
        count[(value / exponent) % 10]++;
    }
    for (int i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }
    for (int i = columns_number - 1; i >= 0; i--){
        int value = columnManager->getValueR(i);
        temp[count[(value / exponent) % 10] - 1] = value;
        count[(value / exponent) % 10]--;
    }
    for (int i = 0; i < columns_number; i++) {
        columnManager->setValue(i, temp[i]);
        columnManager->highlight(i);
    }
}
