#ifndef SEQUENTIALSEARCH_H
#define SEQUENTIALSEARCH_H


class SequentialSearch
{
    public:
        SequentialSearch();
        virtual ~SequentialSearch();
        static int Search(int array[], int length, int value, int& comparisons);
};

#endif // SEQUENTIALSEARCH_H
