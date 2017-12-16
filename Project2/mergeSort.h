
#ifndef MERGESORT_H
#define MERGESORT_H

class MergeSort{
    protected:
        struct Data{
            int size;
            int *sortit;
            int *working;
        };
        Data* a;
    public:
        MergeSort();
        void mergeSort(int,int);
        void merge(int,int,int);
        ~MergeSort();
        void fill(int);
        void print(int);
};

#endif /* MERGESORT_H */

