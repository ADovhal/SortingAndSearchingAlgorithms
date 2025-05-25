#include "BinarySearch.h"
#include <iostream>

BinarySearch::BinarySearch()
{
    std::cout << "Wywolano konstruktor BinarySearch." << std::endl;
}

BinarySearch::~BinarySearch()
{
    std::cout << "Wywolano destruktor BinarySearch." << std::endl;
}

int BinarySearch::Search(const int tab[], int length, int s, int& comparisons) {
    int left = 0;
    int right = length - 1;
    comparisons = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        comparisons++;
        if (tab[mid] == s)
            return mid;

        comparisons++;
        if (tab[mid] < s)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}
