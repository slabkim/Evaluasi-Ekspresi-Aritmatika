#include <iostream>
#include <vector>

using namespace std;

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

int main() {
    vector<int> arr = {34, 25, 100, 98, 80};
    selectionSort(arr);

    cout << "Array yang sudah disortir: ";
    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}
