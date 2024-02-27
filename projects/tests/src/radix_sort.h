#ifndef SRC_RADIX_SORT_H
#define SRC_RADIX_SORT_H

#include "bits/stdc++.h"

using namespace std;

namespace RadixSort {
    /*template <typename T>
    void sort_by_radix(T arr[], const T n);
    template <typename T>
    void count_sort(T arr[], const T n, T exp);
    template <typename T>
    int find_max(T arr[], T n);*/

    /*template<typename T>
    T findMax(vector<T>& arr, T l, T r);
    template <typename T, typename S>
    void sort_by_radix(vector<T>& a, S base, T l, T r);
    template<typename T, typename S>
    void count_sort(vector<T>& arr, S base, T exp, T l, T r)*/

    int findMax(vector<int>& arr, int l, int r);
    void sort_by_radix(vector<int>& a, int base, int l, int r);
    void count_sort(vector<int>& arr, int base, int exp, int l, int r);
}

#endif