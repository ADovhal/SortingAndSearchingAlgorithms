#ifndef INTERSEARCHSTATISTICS_H
#define INTERSEARCHSTATISTICS_H


class InterSearchStatistics
{
    public:
        InterSearchStatistics();
        virtual ~InterSearchStatistics();
        static double InterSearchStats(int length, int max_trials);
        static void TestInterSearch(const char* filename);
};

#endif // INTERSEARCHSTATISTICS_H
