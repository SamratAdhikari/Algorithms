#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& arr) {
    int maxElement = *max_element(arr.begin(), arr.end());
    int minElement = *min_element(arr.begin(), arr.end());
    int range = maxElement - minElement + 1;

    // Create count array and initialize it with zero
    vector<int> count(range, 0);

    // Store the count of each element
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i] - minElement]++;
    }

    // Store the cumulative count
    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    // Output array to store sorted elements
    vector<int> output(arr.size());

    // Build the output array
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - minElement] - 1] = arr[i];
        count[arr[i] - minElement]--;
    }

    // Copy the sorted elements into the original array
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

void printVector(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    cout << "Original vector: ";
    printVector(arr);

    countingSort(arr);

    cout << "Sorted vector in ascending order: ";
    printVector(arr);

    return 0;
}
