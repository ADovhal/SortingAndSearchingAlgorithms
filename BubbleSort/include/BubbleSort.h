#ifndef BUBBLESORT_H
#define BUBBLESORT_H


class BubbleSort
{
    public:
        BubbleSort();
        virtual ~BubbleSort();
        static void Swap(int* tab, int i, int j);
        static int BubbleSort1(int* tab, int length);
        static int BubbleSort2(int* tab, int length);
};

#endif // BUBBLESORT_H
