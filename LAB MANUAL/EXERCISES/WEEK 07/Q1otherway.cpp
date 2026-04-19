//CT-25166           //MEMOONA
#include <iostream>
using namespace std;

class Array2D {
private:
    int rows, cols;
    int** arr;

public:

    //  Default Constructor
    Array2D() {
        rows = cols = 0;
        arr = nullptr;
    }

    // Parameterized Constructor
    Array2D(int r, int c) {
        rows = r;
        cols = c;

        arr = new int*[rows];
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols];
        }

        // initialize with 0
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                arr[i][j] = 0;
    }

    //  Copy Constructor
    Array2D(const Array2D& other) {
        rows = other.rows;
        cols = other.cols;

        arr = new int*[rows];
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                arr[i][j] = other.arr[i][j];
            }
        }
    }

    //  Assignment Operator
    Array2D& operator=(const Array2D& other) {
        if (this == &other)
            return *this;

        // delete old memory
        for (int i = 0; i < rows; i++)
            delete[] arr[i];
        delete[] arr;

        // copy new data
        rows = other.rows;
        cols = other.cols;

        arr = new int*[rows];
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                arr[i][j] = other.arr[i][j];
            }
        }

        return *this;
    }

    //  Indexing Operator []
    int* operator[](int i) {
        return arr[i];
    }

    //  Addition
    Array2D operator+(const Array2D& other) {
        Array2D result(rows, cols);

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.arr[i][j] = arr[i][j] + other.arr[i][j];

        return result;
    }

    //  Subtraction
    Array2D operator-(const Array2D& other) {
        Array2D result(rows, cols);

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.arr[i][j] = arr[i][j] - other.arr[i][j];

        return result;
    }

    //  Multiplication (Matrix Multiplication)
    Array2D operator*(const Array2D& other) {
        Array2D result(rows, other.cols);

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++) {
                result.arr[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.arr[i][j] += arr[i][k] * other.arr[k][j];
                }
            }

        return result;
    }

    //  Display function
    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    //  Destructor
    ~Array2D() {
        for (int i = 0; i < rows; i++)
            delete[] arr[i];
        delete[] arr;
    }
};
int main() {
    Array2D A(2, 2), B(2, 2);

    // Input values
    cout << "Enter values for A:\n";
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> A[i][j];

    cout << "Enter values for B:\n";
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> B[i][j];

    // Operations
    Array2D C = A + B;
    Array2D D = A - B;
    Array2D E = A * B;

    cout << "\nA + B:\n";
    C.display();

    cout << "\nA - B:\n";
    D.display();

    cout << "\nA * B:\n";
    E.display();

    return 0;
}