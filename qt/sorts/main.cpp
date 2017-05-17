#include <iostream>
#include "sortclass.h"

using namespace std;


//int main(int argc, char *argv[])
int main() {
//    QCoreApplication a(argc, argv);
    int arr[5] = {2, 1, 22, 0, -2};

    SortClass *obj = new SortClass(arr, 5);

    obj->pyramidal_sort(arr, 5);
    cout << endl;

//    obj->merge_sort(arr, 5);
//    cout << endl;

//    obj->quick_sort(arr, 5);
//    cout << endl;

    return 0;
}
