#include <iostream>
#include <vector>

using namespace std;

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

int main() {
    vector<int> arr = {849, 204, 1, 90, 84, 11, 90};
    bubbleSort(arr);

    cout << "Array yang sudah disortir: ";
    for (int x : arr) {
        cout << x << " ";
    }
    return 0;
}
