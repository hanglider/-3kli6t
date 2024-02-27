#include "radix_sort.h"

/*
template <typename T>
void RadixSort::sort_by_radix(T arr[], const T n) {
    T max = find_max(arr, n);
    for (T exp = 1; max / exp > 0; exp *= 10) {
        count_sort(arr, n, exp);
    }
}

template <typename T>
void RadixSort::count_sort(T arr[], const T n, T exp) {
    const T BASE = 10;
    T* output = new T[n];
    T count[BASE] = {0};
    for (T i = 0; i < n; i++) {
        count[(arr[i] / exp) % BASE]++;
    }
    for (T i = 1; i < BASE; i++) {
        count[i] += count[i - 1];
    }
    for (T i = n - 1; i >= 0; i--) {
        T elem = (arr[i] / exp) % BASE;
        output[count[elem] - 1] = arr[i];
        count[elem]--;
    }
    for (T i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    delete[] output;
}

template <typename T>
int RadixSort::find_max(T arr[], T n) {
    T max = arr[0];
    for (T i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}*/

/*
template<typename T>
T RadixSort::findMax(vector<T>& arr, T l, T r) {
    T max = arr[l];
    for (auto i = l + 1; i < r; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

template<typename T, typename S>
void RadixSort::count_sort(vector<T>& arr, S base, T exp, T l, T r) {
    auto n = r - l;
    vector<T> output(n);
    vector<T> count(base, 0);

    for (int i = l; i < r; i++) {
        count[(arr[i] / exp) % base]++;
    }
    for (int i = 1; i < base; i++) {
        count[i] += count[i - 1];
    }
    for (int i = r - 1; i >= l; i--) {
        output[count[(arr[i] / exp) % base] - 1] = arr[i];
        count[(arr[i] / exp) % base]--;
    }
    for (int i = l; i < r; i++) {
        arr[i] = output[i];
    }
}

template <typename T, typename S>
void RadixSort::sort_by_radix(vector<T>& a, S base, T l, T r) {
    auto max = findMax(a, l, r);
    for (T exp = l + 1; max / exp > 0; exp *= base) {
        count_sort(a, base, exp, l, r);
    }
}*/

int RadixSort::findMax(vector<int>& arr, int l, int r) {
    auto max = arr[l];
    for (auto i = l + 1; i < r; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

void RadixSort::count_sort(vector<int>& arr, int base, int exp, int l, int r) {
    auto n = r - l;
    vector<int> output(n);
    vector<int> count(base, 0);

    for (int i = l; i < r; i++) {
        count[(arr[i] / exp) % base]++;
    }
    for (int i = 1; i < base; i++) {
        count[i] += count[i - 1];
    }
    for (int i = r - 1; i >= l; i--) {
        output[count[(arr[i] / exp) % base] - 1] = arr[i];
        count[(arr[i] / exp) % base]--;
    }
    for (int i = l; i < r; i++) {
        arr[i] = output[i];
    }
}

void RadixSort::sort_by_radix(vector<int>& a, int base, int l, int r) {
    auto max = findMax(a, l, r);
    for (auto exp = l + 1; max / exp > 0; exp *= base) {
        count_sort(a, base, exp, l, r);
    }
}