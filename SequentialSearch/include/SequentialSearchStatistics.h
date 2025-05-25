#ifndef SEQUENTIALSEARCHSTATISTICS_H
#define SEQUENTIALSEARCHSTATISTICS_H


class SequentialSearchStatistics
{
    public:
        SequentialSearchStatistics();
        virtual ~SequentialSearchStatistics();

        static void TestSearch(const char* filename);

    private:
        static double SequentSearchStatistics(int length, int max, int tableType);
};

#endif // SEQUENTIALSEARCHSTATISTICS_H
