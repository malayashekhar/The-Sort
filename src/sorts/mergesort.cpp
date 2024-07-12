//
// Created by Malaya Shekhar on 12/07/24.
//



#include "mergesort.h"

MergeSort::MergeSort(ColumnManager *columnManager) {
    this->columnManager = columnManager;
}

void MergeSort::sort(){
    MSORT(0, columnManager->getNumber()-1);
}

void MergeSort::MSORT(int low, int high) {
    if(low < high){
        int mid = (low+high) / 2;
        MSORT(low, mid);
        MSORT(mid+1, high);
        merge(low, high, mid);
    }
}

void MergeSort::merge(int low, int high, int mid) {
    int max = columnManager->getNumber();
    int temp[max];
    int left_index = low;
    int right_index = mid+1;
    int temp_index = low;

    while(left_index <= mid && right_index <= high) {
        columnManager->highlight(left_index, right_index);
        if(columnManager->getValue(left_index) <= columnManager->getValue(right_index)) {
            temp[temp_index] = columnManager->getValue(left_index);
            left_index++;
        }
        else {
            temp[temp_index] = columnManager->getValue(right_index);
            right_index++;
        }
        temp_index++;
    }

    while(left_index <= mid) {
        columnManager->highlight(left_index, mid);
        temp[temp_index] = columnManager->getValue(left_index);
        temp_index++;
        left_index++;
    }

    while(right_index <= high) {
        columnManager->highlight(right_index, high);
        temp[temp_index] = columnManager->getValue(right_index);
        temp_index++;
        right_index++;
    }

    for(int i = low; i < temp_index; i++) {
        columnManager->setValue(i, temp[i]);
    }
}
