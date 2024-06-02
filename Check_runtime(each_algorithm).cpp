#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void generateRandomData(vector<int>& arr, int size) {
    arr.clear();
    arr.reserve(size);
    for (int i = 0; i < size; i++) {
        arr.push_back(rand() % 10000);
    }
}

void generateSortedData(vector<int>& arr, int size) {
    arr.clear();
    arr.reserve(size);
    for (int i = 0; i < size; i++) {
        arr.push_back(i);
    }
}

void generateReverseSortedData(vector<int>& arr, int size) {
    arr.clear();
    arr.reserve(size);
    for (int i = 0; i < size; i++) {
        arr.push_back(size - i);
    }
}

template <typename Func>
double measureTime(Func func, vector<int>& arr) {
    auto start = high_resolution_clock::now();
    func(arr);
    auto end = high_resolution_clock::now();
    duration<double> diff = end - start;
    return diff.count();
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void mergeSortWrapper(vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void quickSortWrapper(vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> sizes = {10, 100, 500, 1000, 10000};
    vector<string> algorithms = {"Bubble Sort", "Insertion Sort", "Selection Sort", "Merge Sort", "Quick Sort"};

    for (int size : sizes) {
        cout << "Testing with size: " << size << endl;

        vector<int> arr;
        double time;

        cout << "Random Data:" << endl;

        generateRandomData(arr, size);
        time = measureTime(bubbleSort, arr);
        cout << "Bubble Sort: " << time << " seconds" << endl;

        generateRandomData(arr, size);
        time = measureTime(insertionSort, arr);
        cout << "Insertion Sort: " << time << " seconds" << endl;

        generateRandomData(arr, size);
        time = measureTime(selectionSort, arr);
        cout << "Selection Sort: " << time << " seconds" << endl;

        generateRandomData(arr, size);
        time = measureTime(mergeSortWrapper, arr);
        cout << "Merge Sort: " << time << " seconds" << endl;

        generateRandomData(arr, size);
        time = measureTime(quickSortWrapper, arr);
        cout << "Quick Sort: " << time << " seconds" << endl;

        cout << "Reverse Sorted Data:" << endl;
        generateReverseSortedData(arr, size);
        time = measureTime(bubbleSort, arr);
        cout << "Bubble Sort: " << time << " seconds" << endl;

        generateReverseSortedData(arr, size);
        time = measureTime(insertionSort, arr);
        cout << "Insertion Sort: " << time << " seconds" << endl;

        generateReverseSortedData(arr, size);
        time = measureTime(selectionSort, arr);
        cout << "Selection Sort: " << time << " seconds" << endl;

        generateReverseSortedData(arr, size);
        time = measureTime(mergeSortWrapper, arr);
        cout << "Merge Sort: " << time << " seconds" << endl;

        generateReverseSortedData(arr, size);
        time = measureTime(quickSortWrapper, arr);
        cout << "Quick Sort: " << time << " seconds" << endl;

        cout << "Already Sorted Data:" << endl;
        generateSortedData(arr, size);
        time = measureTime(bubbleSort, arr);
        cout << "Bubble Sort: " << time << " seconds" << endl;

        generateSortedData(arr, size);
        time = measureTime(insertionSort, arr);
        cout << "Insertion Sort: " << time << " seconds" << endl;

        generateSortedData(arr, size);
        time = measureTime(selectionSort, arr);
        cout << "Selection Sort: " << time << " seconds" << endl;

        generateSortedData(arr, size);
        time = measureTime(mergeSortWrapper, arr);
        cout << "Merge Sort: " << time << " seconds" << endl;

        generateSortedData(arr, size);
        time = measureTime(quickSortWrapper, arr);
        cout << "Quick Sort: " << time << " seconds" << endl;

        cout << endl;
    }

    return 0;
}
