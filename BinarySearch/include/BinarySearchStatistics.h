#ifndef BINARYSEARCHSTATISTICS_H
#define BINARYSEARCHSTATISTICS_H


class BinarySearchStatistics
{
    public:
        BinarySearchStatistics();
        virtual ~BinarySearchStatistics();
        static double BSStats( int max, int length);
        static void TestBinarySearch(const char* filename);
};

#endif // BINARYSEARCHSTATISTICS_H
