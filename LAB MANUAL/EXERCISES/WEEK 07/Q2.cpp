//CT-25166           //MEMOONA
#include <iostream>
using namespace std;

class Array2D {
private:
    int rows, cols;
    int** arr;

public:
    // Constructor
    Array2D(int r, int c) {
        rows = r;
        cols = c;

        arr = new int*[rows];
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols];
        }
    }

    // Indexing operator
    int* operator[](int i) {
        return arr[i];
    }

    // 🔥 Binary Search in Matrix
    bool search(int target) {
        int left = 0;
        int right = rows * cols - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            int r = mid / cols;
            int c = mid % cols;

            if (arr[r][c] == target)
                return true;
            else if (arr[r][c] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }

    // Destructor
    ~Array2D() {
        for (int i = 0; i < rows; i++)
            delete[] arr[i];
        delete[] arr;
    }
};

int main() {
    Array2D A(3, 4);

    // Input matrix
    int data[3][4] = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };

    // Fill matrix
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            A[i][j] = data[i][j];

    // Test cases
    cout << A.search(3) << endl;   // Output: 1 (true)
    cout << A.search(13) << endl;  // Output: 0 (false)

    return 0;
}