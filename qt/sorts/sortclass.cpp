#include "sortclass.h"
#include "mergesort.h"
#include "quicksort.h"
#include "pyramidalsort.h"
#include <iostream>

using namespace std;

// constructors
SortClass::SortClass(int arr[], int size) {
    this->source_arr = arr;
    this->size = new int(size);
    this->sorted = false;
}

SortClass::SortClass() {
    cout << "you must define array pointer" << endl;
    return;
}

// public
void SortClass::buble_sort(int *arr, int size) {
    cout << "buble_sort:" << endl;

    if (arr == nullptr) {
        if (this->source_arr == nullptr || this->size == nullptr) {
            cout << "you must define array pointer and size" << endl;
        }
        arr = this->source_arr;
        size = *this->size;
    } else {

        int *i = new int[size];
        for(int k = 0; k < size; ++k)
            i[k] = arr[k];

        this->source_arr = i;
        *this->size = size;
    }

    print_source();

    for(int i = 1; i < size; ++i) {
        for(int j = 0; j < size-i; j++) {
            if(arr[j] > arr[j+1]) {
                // place changing
                swap(arr[j], arr[j+1]);
            }
        }
    }
    this->sorted = true;

    int *s = new int[size];
    for(int k = 0; k < size; ++k)
        s[k] = arr[k];

    this->sorted_arr = s;

    print_sorted();
}


void SortClass::merge_sort (int *arr, int size) {
    cout << "merge_sort:" << endl;

    if (arr == nullptr) {
        if (this->source_arr == nullptr || this->size == nullptr) {
            cout << "you must define array pointer and size" << endl;
        }
        arr = this->source_arr;
        size = *this->size;
    } else {

        int *i = new int[size];
        for(int k = 0; k < size; ++k)
            i[k] = arr[k];

        this->source_arr = arr;
        *this->size = size;
    }

    print_source();

    MergeSort *mrg = new MergeSort();

    mrg->mergeSort(arr, 0, size-1);


    this->sorted = true;

    int *s = new int[size];
    for(int k = 0; k < size; ++k)
        s[k] = arr[k];

    this->sorted_arr = s;
    print_sorted();
}

void SortClass::quick_sort(int arr[], int size) {
    cout << "quick_sort:" << endl;

    if (arr == nullptr) {
        if (this->source_arr == nullptr || this->size == nullptr) {
            cout << "you must define array pointer and size" << endl;
        }
        arr = this->source_arr;
        size = *this->size;
    } else {
        int *i = new int[size];
        for(int k = 0; k < size; ++k)
            i[k] = arr[k];

        this->source_arr = arr;
        *this->size = size;
    }

    print_source();

    QuickSort *qs = new QuickSort();

    qs->quickSort(arr, 0, size - 1);

    this->sorted = true;

    int *s = new int[size];
    for(int k = 0; k < size; ++k)
        s[k] = arr[k];

    this->sorted_arr = s;

    print_sorted();
}

void SortClass::pyramidal_sort(int arr[], int size) {
    cout << "quick_sort:" << endl;

    if (arr == nullptr) {
        if (this->source_arr == nullptr || this->size == nullptr) {
            cout << "you must define array pointer and size" << endl;
        }
        arr = this->source_arr;
        size = *this->size;
    } else {
        int *i = new int[size];
        for(int k = 0; k < size; ++k)
            i[k] = arr[k];

        this->source_arr = arr;
        *this->size = size;
    }

    print_source();

    PyramidalSort *ps = new PyramidalSort();

    qs->quickSort(arr, 0, size - 1);

    this->sorted = true;

    int *s = new int[size];
    for(int k = 0; k < size; ++k)
        s[k] = arr[k];

    this->sorted_arr = s;

    print_sorted();
}


// private
void SortClass::print_sorted() {
    if (this->source_arr == nullptr) {
        cout << "source array not defined" << endl;
        return;
    }
    cout << "sorted arr" << endl;
    for (int i = 0; i < *this->size; ++i) {
        cout << i << ": " << (this->sorted_arr[i]) << endl;
    }
}

void SortClass::print_source() {
    if (this->source_arr == nullptr) {
        cout << "source array not defined" << endl;
        return;
    }
    cout << "source arr" << endl;
    for (int i = 0; i < *this->size; ++i) {
        cout << i << ": " << (this->source_arr[i]) << endl;
    }

}

void SortClass::print_steps_count() {

}
