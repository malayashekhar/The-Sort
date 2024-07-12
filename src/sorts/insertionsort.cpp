//
// Created by Malaya Shekhar on 12/07/24.
//


#include "insertionsort.h"


InsertionSort::InsertionSort(ColumnManager *columnManager){
    this->columnManager = columnManager;
}

void InsertionSort::sort(){
    ISORT();
}

void InsertionSort::ISORT(){
    for(int i = 1; i < columnManager->getNumber(); i++){
        int j = i - 1;
        while(j >= 0 && columnManager->getValue(j) > columnManager->getValue(j+1)){
            columnManager->highlight(j, i);
            columnManager->swap(j, j+1);
            j=j-1;
        }
    }
}

