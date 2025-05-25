#ifndef RANDOM_H
#define RANDOM_H


class Randoms
{
    public:
        Randoms();
        virtual ~Randoms();
        static int* RandomTable(int length);
        static int LosujIndeks(int length);
};

#endif // RANDOM_H
