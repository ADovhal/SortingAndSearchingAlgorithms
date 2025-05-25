#ifndef INTERPOLATION_H
#define INTERPOLATION_H


class Interpolation
{
    public:
    InterpolationSearch();
    virtual ~InterpolationSearch();

    static int Interpolation(int left, int right, int s, const int tab[]);
    static int InterSearch(const int tab[], int length, int s, int& comparisons);
};

#endif // INTERPOLATION_H
