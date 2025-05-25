#ifndef RANDOM_H
#define RANDOM_H


class Random
{
    public:
        Random();
        virtual ~Random();

        static int* RandomTable(int length);
};

#endif // RANDOM_H
