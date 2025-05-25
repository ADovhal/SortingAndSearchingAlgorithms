#ifndef QUICKSORTSTATISTIC_H
#define QUICKSORTSTATISTIC_H


class QuickSortStatistic
{
    public:
        QuickSortStatistic();
        virtual ~QuickSortStatistic();

        static double QuickSortStatistics(int max, int length);
        static void TestQuickSort(const char* filename);

};

#endif // QUICKSORTSTATISTIC_H
