#include "QuickSort.h"
#include <iostream>

QuickSort::QuickSort()
{
    std::cout << "Wywolano konstruktor  \"QuickSort\"." << std::endl;
}

QuickSort::~QuickSort()
{
    std::cout << "Wywolano destruktor \"QuickSort\"." << std::endl;
}

int comparisonCount = 0;

void QuickSort::Swap(int* tab, int i, int j) {
    int temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}

int QuickSort::Sort(int* tab, int left, int right) {
    if (left < right) {
        int pos = left;
        for (int i = left + 1; i <= right; ++i) {
            comparisonCount++;
            if (tab[i] < tab[left]) {
                ++pos;
                Swap(tab, i, pos);
            }
        }
        Swap(tab, left, pos);
        Sort(tab, left, pos - 1);
        Sort(tab, pos + 1, right);
    }
    return comparisonCount;
}
