#ifndef INTERPOLATIONSEARCH_H
#define INTERPOLATIONSEARCH_H


class InterpolationSearch
{
    public:
        InterpolationSearch();
        virtual ~InterpolationSearch();
        static int Interpolation(int left, int right, int s, const int tab[]);
        static int InterSearch(const int tab[], int length, int s, int& comparisons);
};

#endif // INTERPOLATIONSEARCH_H
