//
// Created by Malaya Shekhar on 12/07/24.
//

#include "sort_manager.h"

SortManager::SortManager(WindowManager *windowManager, ColumnManager *columnManager) {
    this->windowManager = windowManager;
    this->columnManager = columnManager;
    this->sortType = 69420; //rand num
    setSorted(false);
    setSortType(0);
}

void SortManager::sort() {
    if(!sorted) {
        std::cout << "SORTING NOW..." << std::endl;
        switch(this->sortType) {
            case 0: {
                BubbleSort BubbleSort(this->columnManager);
                BubbleSort.sort();
                break;
            }

            case 1: {
                InsertionSort InsertionSort(this->columnManager);
                InsertionSort.sort();
                break;
            }

            case 2: {
                SelectionSort SelectionSort(this->columnManager);
                SelectionSort.sort();
                break;
            }

            case 3: {
                RadixSort RadixSort(this->columnManager);
                RadixSort.sort();
                break;
            }

            case 4: {
                MergeSort MergeSort(this->columnManager);
                MergeSort.sort();
                break;
            }

            case 5: {
                QuickSort QuickSort(this->columnManager);
                QuickSort.sort();
                break;
            }

            default:
                break;
        }
        setSorted(true);
    }
}


void SortManager::setSortType(int sortType){
    /* SORT TYPE DICTIONARY:
    *  0: BubbleSort
    *  1: InsertionSort
    *  2: SelectionSort
    *  3: RadixSort
    *  4: MergeSort
    *  5: QuickSort
    */

    std::cout << "Selected Algorithm: ";
    if(sortType != this->sortType) {
        this->sortType = sortType;
        this->windowManager->setTitle(getTitle());
        std::cout << getTitle() << std::endl;
        this->columnManager->generate(this->sortType);
        this->sorted = false;
    }
}

int SortManager::getSortType(){
    return this->sortType;
}

std::string SortManager::getTitle() {
    switch(this->sortType) {
        case 0:
            return "Bubble Sort";
            break;

        case 1:
            return "Insertion Sort";
            break;

        case 2:
            return "Selection Sort";
            break;

        case 3:
            return "Radix Sort";
            break;

        case 4:
            return "Merge Sort";
            break;

        case 5:
            return "Quick Sort";
            break;

        default:
            return "No Title";
            break;
    }
}


void SortManager::setSorted(bool sorted){
    this->sorted = sorted;
    if(this->sorted)    std::cout << "SORTED!" << std::endl << std::endl;
}

bool SortManager::isSorted(){
    return this->sorted;
}
