#ifndef PYRAMIDALSORT_H
#define PYRAMIDALSORT_H


class PyramidalSort {
public:
    PyramidalSort();
    void heapSort(int *arr, int cnt);
    void bst(int *arr, int cnt);
private:
    void DownHeap(int *arr, int index, int cnt, int current);
};

#endif // PYRAMIDALSORT_H
