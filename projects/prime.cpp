#include <execution>
#include <windows.h>
#include "bits/stdc++.h"

using namespace std;

using ll = long long;

#define sqr(x) (x)*(x)
#define all(a) (a).begin(), (a).end()

const auto pi = acos(-1);

#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

template <typename T>
T Binpow (T a, ll n) {T r = 1;while (n) {if (n & 1) r *= a; a *= a; n >>= 1;} return r;}

template <typename T>
auto F(vector<T>& a, T l, T r, function<bool(T, T)> &cmp); //sort for Quicksort

struct T {
    int a, b, c, d;
};

template<typename T>
vector<T> create_copy(std::vector<T> const &vec) {
    std::vector<T> v(vec);
    return v;
}

unordered_map<int, int> factorize(int n) {
    unordered_map<int, int> res;
    for (int i = 2; i * i <= n; ++i) {
        while (!(n % i)) n /= i, res[i]++;
    }
    if (n != 1) res[n]++;
    return res;
}

bool is_prime(int x) {
    if (x < 2) return false;
    if (x == 2)return true;
    if (!(x & 1)) return false;
    for (int j = 3; j * j <= x; ++j)
        if (!(x % j)) return false;
    return true;
}

template <typename T>
void pra(vector<T> &a) {
    for (auto &x : a) cout << x << ' ';
}

//template <typename T>
static function<bool(int, int)> cmp = [](int a, int b) {
    return a > b;
};

struct Node {
    string val;
    Node* next;
    Node(string _val) : val(_val), next(nullptr){}
};


struct List {
    Node* first; Node* last;
    bool is_empty() {
        return first == nullptr;
    }
    void pb(string a) {
        Node* p = new Node(a);
        if (is_empty()) {
            first = p;
            last = p;
        } else {
            last->next = p;
            last = p;
        }
    }
    void clear() {
        first->next = nullptr;
        first->val = "";
    }
    void print() {
        if (is_empty()) return;
        auto x = first;
        while (x) {//while (x->next != nullptr) {
            cout << x->val << char(32);
            x = x->next;
        }
        cout << "\n";
    }
    bool find(string a) {
        auto x = first;
        while (x->val != a) {
            if (x->next == nullptr) return 0;
            x = x->next;
        }
        return 1;
    }
    bool popback() {
        if (first->next != nullptr) {
            auto x = first->next;
            first = x;
            return 1;
        } else return 0;
    }
    auto pop() {
        auto x = first;
        while (x->next != last) {
            x = x->next;
        }
        x->next = nullptr;
        last = x;
        return last->val;
    }
    bool del(string x) {
        if (first->next == nullptr && first->val != x) return 0;
        if (first->next == nullptr && first->val == x) {
            first->next = nullptr;

            return 1;
        }
        auto t = first;
        while (t->next->val != x) {
            t = t->next;
        }
        t = t->next->next;
        return 1;

    }
    string get(int n) {
        if (first->next == nullptr && n == 1) return "";
        auto t = first;
        for (int i = 0; i < n; i++) {
            t = t->next;
        }
        return t->val;
    }
    void remove(string s) {
        while (find(s)) {
            del(s);
        }
    }
    List() : first(nullptr), last(nullptr) {}
};

template <typename T>
void p(T a) {
    cout << a;
}

template <typename T>
T G(vector<T>& a, T l, T r) {
    auto mid = l + (r - l) / 2;
    if (a[l] > a[mid])
        swap(a[l], a[mid]);
    if (a[l] > a[r])
        swap(a[l], a[r]);
    if (a[mid] > a[r])
        swap(a[mid], a[r]);
    return mid;
}

template <typename T>
auto F(vector<T>& a, T l, T r, function<bool(T, T)> &cmp) {
    auto m = G(a, l, r);
    auto mid = a[m];
    swap(a[m], a[r]);
    auto i = l - 1;
    for (auto j = l; j <= r - 1; j++) {
        if (cmp(a[j], mid)) swap(a[++i], a[j]);
    }
    swap(a[i + 1], a[r]);
    return ++i;
}

template <typename T>
void QuickSort(vector<T> &a, T l, T r, function<bool(T, T)> &cmp) {
    if (l < r){
        auto mid = F(a, l, r, ::cmp);
        QuickSort(a, l, mid - 1, ::cmp);
        QuickSort(a, mid + 1, r, ::cmp);
    }
}

template <typename T>
void QuickSort(vector<T> &a) {
    return QuickSort(a, (T)0, (T)a.size(), cmp);
}

template<typename T>
T findMax(vector<T>& arr, T l, T r) {T max = arr[l];
    for (auto i = l + 1; i < r; i++) {if (arr[i] > max) max = arr[i];} return max;}

template<typename T, typename S>
void countSort(vector<T>& arr, S base, T exp, T l, T r) {
    const int n = r - l;
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
void RadixSort(vector<T>& a, S base, T l, T r, function<bool(T, T)> &cmp) {
    auto max = findMax(a, l, r);
    for (T exp = l + 1; max / exp > 0; exp *= base) {
        countSort(a, base, exp, l, r);
    }
}

template <typename T, typename S>
void RadixSort(vector<T>& a, S base, T l, T r) {
    auto max = findMax(a, l, r);
    for (T exp = l + 1; max / exp > 0; exp *= base) {
        countSort(a, base, exp, l, r);
    }
}

template <typename T, typename S>
void RadixSort(vector<T>& a, S base) {
    return RadixSort(a, base, (T)0, (T)a.size());
}


const int osn = 1024*128;
const int size_num = 10;
const int steps = 4;

unsigned get_last_n_bits( unsigned u, int n ) {
    return u & ~(~0U << n);
}

vector<int>all [osn];
void radix_sort(std::vector<uint32_t>& tmp, int l, int r, int num_buck){
    if (num_buck==-1){
        return;
    }
    if (r-l<=1){
        return;
    }
    for (int i=l; i<r; i++){
        int diff = get_last_n_bits(tmp[i] >> (size_num*num_buck),size_num);
        all[diff].push_back(tmp[i]);
    }
    int pos = 0;
    int last = l;
    for (int i=l; i < r; i++){
        if (all[pos].empty()){
            while (pos < osn && all[pos].empty()){
                pos++;
            }
            last = i;
        }
        tmp[i]=all[pos].back();
        all[pos].pop_back();
    }
    int last_pos = l;
    int last_type = get_last_n_bits(tmp[l] >> (size_num*num_buck),size_num);
    for (int i=l; i < r; i++){
        int curtype = get_last_n_bits(tmp[i] >> (size_num*num_buck),size_num);
        if (last_type!=curtype){
            radix_sort(tmp,last_pos,i,num_buck - 1);
            last_pos = i;
            last_type = curtype;
        }
    }
    radix_sort(tmp,last_pos,r,num_buck - 1);
}

void fast_sort(std::vector<uint32_t>& a){
    radix_sort(a,0,a.size(),steps - 1);
}

template <typename T>
void fast_sort_by_trofimov(std::vector<T>& a) {
    RadixSort(a, 1e6);
}

template <typename T>
void BubbleSort(vector<T>& a){
    int sw = 0, sr = 0;
    for (auto i = 0; i < a.size(); i++){
        for (auto j = i + 1; j < a.size(); j++){
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
                sw++;
            }
            sr++;
        }
    }
    printf("swaps %d compare %d\n", sw, sr);
}

template <typename T>
void SelectionSort(vector<T>&arr){
    int sw = 0, sr = 0;
    for (int i = 0; i < arr.size() - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < arr.size(); j++){
            sr++;
            if (arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        if (min_index != i){
            swap(arr[i], arr[min_index]);
            sw++;
        }
    }
    printf("swaps %d compare %d\n", sw, sr);
}

struct Data {
    int value;
    string RED, GREEN, BLUE, BLACK;
};


signed main() {

    return 0;
}