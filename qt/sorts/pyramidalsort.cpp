#include "pyramidalsort.h"
#include <iostream>

using namespace std;

PyramidalSort::PyramidalSort()
{

}


void PyramidalSort::DownHeap(int *arr, int index, int cnt, int current) {
    int child;

    while (index < (cnt/2)) {
        child = (index+1)*2-1;

        if ((child < cnt-1) && (arr[child] < arr[child+1]))
            child++;
        if (current >= arr[child])
            break;

        arr[index] = arr[child];
        index = child;
    }
    arr[index] = current;
}

void PyramidalSort::heapSort(int *arr, int cnt) {

    int i;
    int current;

    for (i = (cnt/2)-1; i > 0; i--)
        DownHeap(arr, i, cnt, arr[i]);

    for(i = 0; i < cnt ; i++)
        cout << arr[i] << " ";
    cout << endl;

    for (i = cnt-1; i > 0; i--) {
        current = arr[i];
        arr[i] = arr[0];
        DownHeap(arr, 0, i, current);
    }



//    return steps;
}

void PyramidalSort::bst(int *arr, int cnt) {

    int i;
    int current;

    int level = 1;
    int k = 0;
    for(i = 0; i < cnt ; i++) {
        cout << arr[i] << " ";
        ++k;
//        if (k == level) {
//            k = 0;
//            level = level * 2;
//            cout << endl;
//        }
    }
//    cout << endl;
}
