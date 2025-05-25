#include "InterpolationSearch.h"
#include <iostream>

InterpolationSearch::InterpolationSearch()
{
    std::cout << "Wywolano konstruktor \"InterpolationSearch\"." << std::endl;
}

InterpolationSearch::~InterpolationSearch()
{
    std::cout << "Wywolano destruktor \"InterpolationSearch\"." << std::endl;
}

int InterpolationSearch::Interpolation(int left, int right, int s, const int tab[]) {
    if (tab[right] == tab[left]) return left;
    return left + ((s - tab[left]) * (right - left)) / (tab[right] - tab[left]);
}

int InterpolationSearch::InterSearch(const int tab[], int length, int s, int& comparisons) {
    int left = 0;
    int right = length - 1;
    comparisons = 0;

    while (left <= right && s >= tab[left] && s <= tab[right]) {
        int mid = Interpolation(left, right, s, tab);

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
