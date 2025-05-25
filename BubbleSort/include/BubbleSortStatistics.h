#ifndef BUBBLESORTSTATISTICS_H
#define BUBBLESORTSTATISTICS_H


class BubbleSortStatistics
{
    public:
        BubbleSortStatistics();
        virtual ~BubbleSortStatistics();
        static double BubbleSortStatistics1(int max, int length);
        static double BubbleSortStatistics2(int max, int length);
        static void TestBubbleSort1(const char* filename);
        static void TestBubbleSort2(const char* filename);
};

#endif // BUBBLESORTSTATISTICS_H
