#include <iostream>
#include <windows.h>
#include <vector>

int main() {

    SetConsoleOutputCP(CP_UTF8);

    std::vector<int> arr = {1, 1};
    std::cout << "Первый 10 чисел Фибоначчи:\n";
    for (int i = 1; i < 9; i++) {
        arr.push_back(arr[i] + arr[i-1]);
    }
    for (auto &x : arr) {
        std::cout << x << ' ';
    }
    system("PAUSE");
}
