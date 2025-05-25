#include "QuickSortStatistic.h"
#include "QuickSort.h"
#include "Random.h"
#include <fstream>
#include <iostream>
#include <iomanip>

extern int comparisonCount;

QuickSortStatistic::QuickSortStatistic()
{
    std::cout << "Wywolano konstruktor domyslny \"QuickSortStatistic\"." << std::endl;
}

QuickSortStatistic::~QuickSortStatistic()
{
    std::cout << "Wywolano destruktor \"QuickSortStatistic\"." << std::endl;
}

double QuickSortStatistic::QuickSortStatistics(int max, int length) {
    int totalComparisons = 0.0;
    for (int i = 0; i < max; ++i) {
        int* array = Random::RandomTable(length);
        comparisonCount = 0;
        QuickSort::Sort(array, 0, length - 1);
        totalComparisons += comparisonCount;
        delete[] array;
    }
    return static_cast<double>(totalComparisons)/ max;
}

void QuickSortStatistic::TestQuickSort(const char* filename) {

    std::ofstream file(filename);
    file << "Rozmiar tablicy \t Srednia liczba porownan\n";

    for (int length = 10; length <= 1000; length += 10) {
        double averageComparisons = QuickSortStatistics(1000, length);

        file << std::setw(10) << length
             << std::fixed << std::setprecision(2)
             << std::setw(15) << "\t" << averageComparisons
             << "\n";
    }

    file.close();
}
