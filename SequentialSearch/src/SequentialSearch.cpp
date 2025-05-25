#include "SequentialSearch.h"
#include <iostream>

SequentialSearch::SequentialSearch()
{
    std::cout << "Wywolano konstruktor SequentialSearch." << std::endl;
}

SequentialSearch::~SequentialSearch()
{
    std::cout << "Wywolano destruktor SequentialSearch." << std::endl;
}

int SequentialSearch::Search(int array[], int length, int value, int& comparisons) {
    comparisons = 0;
    for (int i = 0; i < length; ++i) {
        ++comparisons;
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}
