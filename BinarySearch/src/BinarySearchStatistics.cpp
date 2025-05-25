#include "BinarySearchStatistics.h"
#include "Randoms.h"
#include "QuickSort.h"
#include "BinarySearch.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <iomanip>

BinarySearchStatistics::BinarySearchStatistics()
{
    std::cout << "Wywolano konstruktor \"BinarySearchStatistic\"." << std::endl;
}

BinarySearchStatistics::~BinarySearchStatistics()
{
    std::cout << "Wywolano destruktor \"BinarySearchStatistic\"." << std::endl;
}

double BinarySearchStatistics::BSStats(int max, int length) {
    int* tab = new int[length];
    int totalComparisons = 0;

    for (int j = 0; j < max; ++j) {
        tab = Randoms::RandomTable(length);

        QuickSort::Sort(tab, 0, length - 1);

        int idx = Randoms::LosujIndeks(length);
        int s = tab[idx];

        int comparisons = 0;
        BinarySearch::Search(tab, length, s, comparisons);

        totalComparisons += comparisons;
    }

    delete[] tab;

    return static_cast<double>(totalComparisons) / max;
}

void BinarySearchStatistics::TestBinarySearch(const char* filename) {

    std::ofstream file(filename);
    file << "Rozmiar tablicy \t Srednia liczba porownan\n";
    for (int size = 10; size <= 1000; size += 10) {
        double avg = BSStats(1000, size);
        file << std::setw(10) << size
             << std::fixed << std::setprecision(2)
             << std::setw(15) << "\t" << avg
             << "\n";
        std::cout << "Rozmiar: " << size << ", Srednia porownan: " << avg << "\n";
    }

    file.close();
}
