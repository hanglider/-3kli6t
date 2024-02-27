#ifndef SRC_RADIX_SORT_H
#define SRC_RADIX_SORT_H

namespace RadixSort {
    template <typename T>
    void sort_by_radix(T arr[], const T n);
    template <typename T>
    void count_sort(T arr[], const T n, T exp);
    template <typename T>
    int find_max(T arr[], T n);
}

#endif //SRC_RADIX_SORT_H