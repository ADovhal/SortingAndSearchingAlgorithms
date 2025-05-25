#include "SequentialSearchStatistics.h"
#include <iostream>
#include <ctime>

int main()
{
    srand(time(nullptr));

    SequentialSearchStatistics::TestSearch("wyszukiwanie1.dat");
    SequentialSearchStatistics::TestSearch("wyszukiwanie2.dat");

    std::cout << "Koniec dzialania programu. Wyniki zapisane w podanych powyzej plikach." << std::endl;

    return 0;
}
