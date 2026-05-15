#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

// User-defined Bubble Sort Function
void Sort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to display vector
void display(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int N;

    cout << "Enter number of integers: ";
    cin >> N;

    vector<int> vec(N);

    cout << "Enter " << N << " integers:\n";

    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }

    // Copy vectors for both sorting methods
    vector<int> vec1 = vec;
    vector<int> vec2 = vec;

    // ---------------- USER-DEFINED SORT ----------------
    auto start1 = high_resolution_clock::now();

    Sort(vec1);

    auto stop1 = high_resolution_clock::now();

    auto duration1 =
        duration_cast<microseconds>(stop1 - start1);

    // ---------------- STL SORT ----------------
    auto start2 = high_resolution_clock::now();

    sort(vec2.begin(), vec2.end());

    auto stop2 = high_resolution_clock::now();

    auto duration2 =
        duration_cast<microseconds>(stop2 - start2);

    // Display results
    cout << "\nSorted Vector using User-defined Sort:\n";
    display(vec1);

    cout << "\nSorted Vector using STL sort():\n";
    display(vec2);

    // Display time taken
    cout << "\nTime taken by User-defined Sort: "
         << duration1.count() << " microseconds";

    cout << "\nTime taken by STL sort(): "
         << duration2.count() << " microseconds";

    return 0;
}