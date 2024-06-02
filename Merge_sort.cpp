#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int kiri, int tengah, int kanan) {
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[kiri + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[tengah + 1 + i];

    int i = 0, j = 0, k = kiri;
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

void mergeSort(vector<int>& arr, int kiri, int kanan) {
    if (kiri < kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        mergeSort(arr, kiri, tengah);
        mergeSort(arr, tengah + 1, kanan);
        merge(arr, kiri, tengah, kanan);
    }
}

int main() {
    vector<int> arr = {100, 1002, 1002, 302, 39, 2, 10};
    mergeSort(arr, 0, arr.size() - 1);

    cout << "Array yang sudah disortir: ";
    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}