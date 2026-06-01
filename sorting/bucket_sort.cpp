#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(vector<float>& arr) {
    int n = arr.size();

    // Create n buckets
    vector<vector<float>> buckets(n);

    // Put elements into buckets
    for (int i = 0; i < n; i++) {
        int index = n * arr[i];
        buckets[index].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate all buckets into arr
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (float x : buckets[i]) {
            arr[k++] = x;
        }
    }
}

int main() {
    vector<float> arr = {
        0.78, 0.17, 0.39, 0.26,
        0.72, 0.94, 0.21, 0.12,
        0.23, 0.68
    };

    bucketSort(arr);

    cout << "Sorted array:\n";
    for (float x : arr)
        cout << x << " ";

    return 0;
}