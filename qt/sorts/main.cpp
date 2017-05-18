#include <iostream>
#include <stdio.h>
#include <x86intrin.h>
#include <QtGlobal>
#include "sortclass.h"

using namespace std;


//int main(int argc, char *argv[])
int main() {
//    QCoreApplication a(argc, argv);
    int arr[10];// = {2, 1, 22, 0, -2, 1,2,3,4,5,6};

    for (int i = 0; i < 11; i++) {
        arr[i] = random() % 10;
    }

    SortClass *obj = new SortClass(arr, 5);

    quint64 i, j;

//    i = __rdtsc();
//    cout << "buble" << endl;
//    obj->buble_sort(arr, 11);
//    j = __rdtsc();
//    cout << "dT: " << j - i;
//    cout << endl<< endl;

//    i = __rdtsc();
//    cout << "merge" << endl;
//    obj->merge_sort(arr, 11);
//    cout << "dT: " << __rdtsc() - i;
//    cout << endl<< endl;

    i = __rdtsc();
    cout << "pyramid" << endl;
    obj->pyramidal_sort(arr, 11);
    cout << "dT: " << __rdtsc() - i;
    cout << endl << endl;

//    i = __rdtsc();
//    cout << "qiick" << endl;
//    obj->quick_sort(arr, 11);

//    cout << "dT: " << ( __rdtsc() - i);
//    cout << endl<< endl ;

//    obj->merge_sort(arr, 5);
//    cout << endl;

//    obj->quick_sort(arr, 5);
//    cout << endl;

    return 0;
}
