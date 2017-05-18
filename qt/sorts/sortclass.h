#ifndef SORTCLASS_H
#define SORTCLASS_H


class SortClass
{
public:
    SortClass();
    SortClass(int arr[], int size);
    void merge_sort(int *arr, int size);
    void quick_sort(int *arr, int size);
    void buble_sort(int *arr, int size);
    void pyramidal_sort(int *arr, int size);

private:
    int *source_arr;
    int *sorted_arr;
    int *size;
    bool sorted;
    void print_source();
    void print_sorted();
};

#endif // SORTCLASS_H
