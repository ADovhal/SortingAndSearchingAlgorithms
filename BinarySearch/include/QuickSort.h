#ifndef QUICKSORT_H
#define QUICKSORT_H


class QuickSort
{
    public:
        QuickSort();
        virtual ~QuickSort();
        static void Swap(int* array, int i, int j);
        static void Sort(int* array, int left, int right);

};

#endif // QUICKSORT_H
