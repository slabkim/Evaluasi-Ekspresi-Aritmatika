#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int bawah, int atas) {
    int pivot = arr[atas];
    int i = (bawah - 1);

    for (int j = bawah; j <= atas - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[atas]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int bawah, int atas) {
    if (bawah < atas) {
        int pi = partition(arr, bawah, atas);
        quickSort(arr, bawah, pi - 1);
        quickSort(arr, pi + 1, atas);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    quickSort(arr, 0, arr.size() - 1);

    cout << "Array yang sudah disortir: ";
    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}
