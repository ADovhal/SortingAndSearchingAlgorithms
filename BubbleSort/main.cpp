#include <iostream>
#include "BubbleSortStatistics.h"

using namespace std;

int main()
{
    srand(time(nullptr));

    BubbleSortStatistics::TestBubbleSort1("bubblesort1.dat");
    BubbleSortStatistics::TestBubbleSort2("bubblesort2.dat");

    std::cout << "Testowanie zakonczone. Wyniki zapisane w plikach." << std::endl;
    return 0;
}
