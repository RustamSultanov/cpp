#include "sortclass.h"
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
void SortClass::buble_sort(int *arr = nullptr, int size = 0) {
    if (arr == nullptr) {
        if (this->source_arr == nullptr || this->size == nullptr) {
            cout << "you must define array pointer and size" << endl;
        }
        arr = this->source_arr;
        size = *this->size;
    } else {
        this->source_arr = arr;
        *this->size = size;
    }

    print_source();

    for(int i = 1; i < size; ++i) {
        for(int j = 0; j < size-i; j++) {
            if(arr[j] > arr[j+1]) {
                // change
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    this->sorted = true;
    this->sorted_arr = arr;
    print_sorted();
}


void SortClass::merge_sort (int *arr = nullptr, int size = 0) {
    if (arr == nullptr) {
        if (this->source_arr == nullptr || this->size == nullptr) {
            cout << "you must define array pointer and size" << endl;
        }
        arr = this->source_arr;
        size = *this->size;
    } else {
        this->source_arr = arr;
        *this->size = size;
    }

    print_source();



    this->sorted = true;
    this->sorted_arr = arr;
    print_sorted();
}

void SortClass::quick_sort(int *arr = nullptr, int size = 0) {

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
