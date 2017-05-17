#ifndef MERGESORT_H
#define MERGESORT_H


class MergeSort
{
public:
    MergeSort();
    void mergeSort(int *arr, int l, int r);
private:
    void merge(int *arr, int l, int m, int r);
};

#endif // MERGESORT_H
