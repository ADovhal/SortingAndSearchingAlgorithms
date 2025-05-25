#include "InterSearchStatistics.h"
#include "Randoms.h"
#include "InterpolationSearch.h"
#include "QuickSort.h"
#include <iostream>
#include <fstream>
#include <iomanip>

InterSearchStatistics::InterSearchStatistics()
{
    std::cout << "Wywolano konstruktor InterSearchStatistics." << std::endl;
}

InterSearchStatistics::~InterSearchStatistics()
{
    std::cout << "Wywolano destruktor InterSearchStatistics." << std::endl;
}

double InterSearchStatistics::InterSearchStats(int max, int length) {
    int* tab = new int[length];
    int totalComparisons = 0;

    for (int j = 0; j < max; ++j) {
        tab = Randoms::RandomTable(length);
        //std::cout<<"Tablica nie posortowana" << std::endl;

        //for(int testOut = 0; testOut < length; ++testOut){

            //std::cout<<tab[testOut] << std::endl;
        //}

        QuickSort::Sort(tab, 0, length - 1);

        //std::cout<<"Tablica posortowana" << std::endl;

        //for(int testOut = 0; testOut < length; ++testOut){
        //    std::cout<<tab[testOut] << std::endl;
        //}

        int idx = Randoms::LosujIndeks(length);
        int s = tab[idx];

        int comparisons = 0;
        InterpolationSearch::InterSearch(tab, length, s, comparisons);

        totalComparisons += comparisons;
    }

    delete[] tab;

    return static_cast<double>(totalComparisons) / max;
}

void InterSearchStatistics::TestInterSearch(const char* filename) {

    std::ofstream file(filename);
    file << "Rozmiar tablicy \t Srednia liczba porownan\n";
    for (int size = 10; size <= 1000; size += 10) {
        double avg = InterSearchStats(1000, size);
        file << std::setw(10) << size
             << std::fixed << std::setprecision(2)
             << std::setw(15) << "\t" << avg
             << "\n";
        std::cout << "Rozmiar: " << size << ", Srednia porownan: " << avg << "\n";
    }

    file.close();
}
