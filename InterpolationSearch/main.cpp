#include "InterSearchStatistics.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    InterSearchStatistics::TestInterSearch("intersearch.dat");

    std::cout << "Testowanie zakonczone. Wyniki zapisane w plikach." << std::endl;

    return 0;
}
