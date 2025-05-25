#include <iostream>
#include "QuickSortStatistic.h"
#include "Random.h"

int main() {

    srand(static_cast<unsigned>(time(nullptr)));

    QuickSortStatistic::TestQuickSort("quicksort.dat");

    std::cout << "Statystyka zapisana do pliku quicksort.dat\n" << std::endl;
    return 0;
}
