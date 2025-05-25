#include "Randoms.h"
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

int Randoms::LosujIndeks(int length) {
    int r;
    do {
        r = rand();
    } while (r > length - 1);
    return r;
}
