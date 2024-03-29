#include <iostream>
#include <windows.h>

template <typename T>
void count_sort(T arr[], const T n, T exp);

template <typename T>
int find_max(T arr[], T n);

template <typename T>
void sort_by_radix(T arr[], const T n) {
    T max = find_max(arr, n);
    for (T exp = 1; max / exp > 0; exp *= 10) {
        count_sort(arr, n, exp);
    }
}

template <typename T>
void count_sort(T arr[], const T n, T exp) {
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
int find_max(T arr[], T n) {
    T max = arr[0];
    for (T i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {

    SetConsoleOutputCP(CP_UTF8);

    int arr[] = { 0xf, 2, 5 , 1, 0};
    const int arr_size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Массив до сортировки:";
    for (int i = 0; i < arr_size; i++) {
        std::cout << ' ' << arr[i];
    }
    std::cout << std::endl;

    sort_by_radix(arr, arr_size);

    std::cout << "Массив после сортировки:";
    for (int i = 0; i < arr_size; i++) {
        std::cout << ' ' << arr[i];
    }
    std::cout << std::endl;

    std::system("PAUSE");
    return 0;
}