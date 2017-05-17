#ifndef PYRAMIDALSORT_H
#define PYRAMIDALSORT_H


class PyramidalSort
{
public:
    PyramidalSort();
    void pyramidalSort();
    void heapSort(int Arr[], int Count);
private:
    void DownHeap(int Arr[], int index, int Count, int Current);
}

#endif // PYRAMIDALSORT_H
