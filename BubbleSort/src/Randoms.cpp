#include "Randoms.h"
#include <cstdlib>
#include <iostream>

Randoms::Randoms()
{
    std::cout << "Wywolano konstruktor \"Randoms\"." << std::endl;
}

Randoms::~Randoms()
{
    std::cout << "Wywolano destruktor \"Randoms\"." << std::endl;
}

int* Randoms::RandomTable(int length) {

    int* array = new int[length];
    for (int i = 0; i < length; ++i) {
        array[i] = rand();
    }
    return array;
}
