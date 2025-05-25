#include "Random.h"
#include <cstdlib>
#include <iostream>

Random::Random()
{
    std::cout << "Wywolano konstruktor \"Random\"." << std::endl;
}

Random::~Random()
{
    std::cout << "Wywolano destruktor \"Random\"." << std::endl;
}

int* Random::RandomTable(int length) {
    int* array = new int[length];
    for (int i = 0; i < length; ++i) {
        array[i] = rand();
    }
    return array;
}
