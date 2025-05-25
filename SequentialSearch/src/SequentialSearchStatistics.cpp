#include "SequentialSearchStatistics.h"
#include "Randoms.h"
#include "SequentialSearch.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>

SequentialSearchStatistics::SequentialSearchStatistics()
{
    std::cout << "Wywolano konstruktor" << std::endl;
}

SequentialSearchStatistics::~SequentialSearchStatistics()
{
    std::cout << "Wywolano destruktor" << std::endl;
}

double SequentialSearchStatistics::SequentSearchStatistics(int length, int max, int tableType) {
    int totalComparisons = 0;

    for (int i = 0; i < max; ++i) {
        int* array = nullptr;

        if (tableType == 1) {
            array = Randoms::RandomTable1(length);
        } else if (tableType == 2) {
            array = Randoms::RandomTable2(length);
        } else {
            std::cerr << "Nieznany typ tabeli!" << std::endl;
            return 0;
        }

        int randomIndex = Randoms::LosujIndeks(length);
        int value = array[randomIndex];

        int comparisons;
        SequentialSearch::Search(array, length, value, comparisons);

        totalComparisons += comparisons;
        delete[] array;
    }

    return static_cast<double>(totalComparisons) / max;
}

void SequentialSearchStatistics::TestSearch(const char* filename) {

    int tableType = 0;

    if (strstr(filename, "1") != nullptr) {
        tableType = 1;
    } else if (strstr(filename, "2") != nullptr) {
        tableType = 2;
    } else {
        std::cerr << "Nie rozpoznano typu tabeli z nazwy pliku: " << filename << std::endl;
        return;
    }

    std::ofstream file(filename);

    file << "Rozmiar tablicy \t Srednia liczba porownan\n";

    for (int length = 10; length <= 1000; length += 10) {
        double averageComparisons = SequentSearchStatistics(length, 100, tableType);

        file << std::setw(10) << length
             << std::fixed << std::setprecision(2)
             << std::setw(15) << "\t" << averageComparisons
             << "\n";
    }

    file.close();

    std::cout << "Zapisywanie wynikow zakonczone." << std::endl;

}
