#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H


class BinarySearch
{
    public:
        BinarySearch();
        virtual ~BinarySearch();
        static int Search(const int tab[], int length, int s, int& comparisons);
};

#endif // BINARYSEARCH_H
