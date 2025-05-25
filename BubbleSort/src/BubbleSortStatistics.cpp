#include "BubbleSortStatistics.h"
#include "BubbleSort.h"
#include "Randoms.h"
#include <fstream>
#include <iostream>
#include <iomanip>

BubbleSortStatistics::BubbleSortStatistics()
{
    std::cout << "Wywolano konstruktor \"BubbleSortStatistics\"." << std::endl;
}

BubbleSortStatistics::~BubbleSortStatistics()
{
    std::cout << "Wywolano destruktor \"BubbleSortStatistics\"." << std::endl;
}

double BubbleSortStatistics::BubbleSortStatistics1(int max, int length) {

    int totalComparisons = 0;
    for (int i = 0; i < max; ++i) {
        int* array = Randoms::RandomTable(length);
        totalComparisons += BubbleSort::BubbleSort1(array, length);
        delete[] array;
    }
    return static_cast<double>(totalComparisons) / max;
}

double BubbleSortStatistics::BubbleSortStatistics2(int max, int length) {

    int totalComparisons = 0;
    for (int i = 0; i < max; ++i) {
        int* array = Randoms::RandomTable(length);
        totalComparisons += BubbleSort::BubbleSort2(array, length);
        delete[] array;
    }
    return static_cast<double>(totalComparisons) / max;
}

void BubbleSortStatistics::TestBubbleSort1(const char* filename) {

    std::cout << "Trwa testowanie BubbleSearch v1." << std::endl;

    std::ofstream file(filename);
    file << "Rozmiar_tablicy \t Srednia_liczba_porownan\n";
    for (int length = 10; length <= 1000; length += 10) {
        double avg = BubbleSortStatistics1(1000, length);
        file << std::setw(10) << length
             << std::fixed << std::setprecision(2)
             << std::setw(15) << "\t" << avg
             << "\n";
    }
    file.close();

    std::cout << "Testowanie BubbleSearch v1 zakonczone." << std::endl;
}

void BubbleSortStatistics::TestBubbleSort2(const char* filename) {

    std::cout << "Trwa testowanie BubbleSearch v2." << std::endl;

    std::ofstream file(filename);
    file << "Rozmiar_tablicy \t Srednia_liczba_porownan\n";
    for (int length = 10; length <= 1000; length += 10) {
        double avg = BubbleSortStatistics2(1000, length);
        file << std::setw(10) << length
             << std::fixed << std::setprecision(2)
             << std::setw(15) << "\t" << avg
             << "\n";
    }
    file.close();

    std::cout << "Testowanie BubbleSearch v1 zakonczone." << std::endl;
}
