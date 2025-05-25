#include "BubbleSort.h"
#include <iostream>

BubbleSort::BubbleSort()
{
    std::cout << "Wywolano konstruktor \"BubbleSort\"." << std::endl;
}

BubbleSort::~BubbleSort()
{
    std::cout << "Wywolano destruktor \"BubbleSort\"." << std::endl;
}

void BubbleSort::Swap(int* tab, int i, int j) {
    int temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}

int BubbleSort::BubbleSort1(int* tab, int length) {

    int comparisons = 0;
    int ch;
    do {
        ch = 0;
        for (int i = 0; i < length - 1; ++i) {
            ++comparisons;
            if (tab[i] > tab[i + 1]) {
                Swap(tab, i, i + 1);
                ch = 1;
            }
        }
    } while (ch != 0);
    return comparisons;
}

int BubbleSort::BubbleSort2(int* tab, int length) {

    int comparisons = 0;
    int ch;
    int p = 0;
    do {
        ch = 0;
        for (int i = 0; i < length - 1 - p; ++i) {
            ++comparisons;
            if (tab[i] > tab[i + 1]) {
                Swap(tab, i, i + 1);
                ch = 1;
            }
        }
        ++p;
    } while (ch != 0);
    return comparisons;
}
