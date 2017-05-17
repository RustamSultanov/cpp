#include "pyramidalsort.h"

PyramidalSort::PyramidalSort()
{

}

void DownHeap(int Arr[], int index, int Count, int Current) {
    int Child;

    while (index < (Count/2)) {
        Child = (index+1)*2-1;

        if ((Child < Count-1) && (Arr[Child] < Arr[Child+1]))
            Child++;
        if (Current >= Arr[Child])
            break;

        Arr[index] = Arr[Child];
        index = Child;
    }
    Arr[index] = Current;
}

void heapSort(int Arr[], int Count) {

    int i;
    int Current;

    for (i = (Count/2)-1; i > 0; i--)
        DownHeap(Arr, i, Count, Arr[i]);

    for (i = Count-1; i > 0; i--) {
        Current = Arr[i];
        Arr[i] = Arr[0];
        DownHeap(Arr, 0, i, Current);
    }
}
