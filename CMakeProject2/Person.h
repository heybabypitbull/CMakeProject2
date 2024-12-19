#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

class Person {
public:
    std::string name;
    int age;

    Person(std::string n, int a);
    bool operator<(const Person& other) const;
};


template <typename T>
void quickSort(std::vector<T>& arr, int left, int right) {
    if (left >= right) return;
    int pivotIndex = right;
    T pivot = arr[pivotIndex];
    int i = left, j = right - 1;

    while (i <= j) {
        while (i <= j && arr[i] < pivot) i++;
        while (i <= j && !(arr[j] < pivot)) j--;
        if (i < j) std::swap(arr[i++], arr[j--]);
    }
    std::swap(arr[i], arr[pivotIndex]);

    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}
