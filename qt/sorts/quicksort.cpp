#include "quicksort.h"
#include <iostream>
using namespace std;

QuickSort::QuickSort()
{

}

void QuickSort::quickSort(int *arr, int l, int r) {
    int x = arr[l + (r - l) / 2];

    int i = l;
    int j = r;

    while(i <= j) {
        while(arr[i] < x) i++;
        while(arr[j] > x) j--;

        if(i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (i<r)
        quickSort(arr, i, r);

    if (l<j)
        quickSort(arr, l, j);
}
