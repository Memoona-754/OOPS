#include <iostream>
#include <stdexcept>
using namespace std;

class Array2D {
private:
    int** data;   // pointer-to-pointer (double pointer)
    int rows;
    int cols;

    // Internal helper: allocate memory
    void allocate(int r, int c) {
        rows = r;
        cols = c;
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols]();   // zero-initialise
        }
    }

    // Internal helper: free memory
    void deallocate() {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;
        data = nullptr;
    }

public:
    Array2D() : data(nullptr), rows(0), cols(0) {
        cout << "[Default Constructor] Empty 2D array created.\n";
    }

    Array2D(int r, int c, int initVal = 0) {
        if (r <= 0 || c <= 0)
            throw invalid_argument("Dimensions must be positive.");
        allocate(r, c);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = initVal;
        cout << "[Parameterised Constructor] " << rows << "x" << cols
             << " array created (init=" << initVal << ").\n";
    }

    // ── 3. COPY CONSTRUCTOR ────────────────────────────────────
    Array2D(const Array2D& other) {
        allocate(other.rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = other.data[i][j];
        cout << "[Copy Constructor] Copied " << rows << "x" << cols << " array.\n";
    }

    // ── 4. DESTRUCTOR ─────────────────────────────────────────
    ~Array2D() {
        if (data) {
            deallocate();
            cout << "[Destructor] Memory freed for " << rows << "x" << cols << " array.\n";
        }
    }

    // ── 5. OVERLOADED ASSIGNMENT OPERATOR (=) ─────────────────
    Array2D& operator=(const Array2D& other) {
        if (this == &other) return *this;        // self-assignment guard
        deallocate();
        allocate(other.rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] = other.data[i][j];
        cout << "[Assignment Operator] Assigned " << rows << "x" << cols << " array.\n";
        return *this;
    }

    // ── 6. OVERLOADED + OPERATOR ──────────────────────────────
    Array2D operator+(const Array2D& other) const {
        if (rows != other.rows || cols != other.cols)
            throw invalid_argument("Dimensions must match for addition.");
        Array2D result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    // ── 7. OVERLOADED - OPERATOR ──────────────────────────────
    Array2D operator-(const Array2D& other) const {
        if (rows != other.rows || cols != other.cols)
            throw invalid_argument("Dimensions must match for subtraction.");
        Array2D result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] - other.data[i][j];
        return result;
    }

    // ── 8. OVERLOADED * OPERATOR (matrix multiplication) ─────
    Array2D operator*(const Array2D& other) const {
        if (cols != other.rows)
            throw invalid_argument(
                "For A*B: A's cols must equal B's rows.");
        Array2D result(rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++)
                for (int k = 0; k < cols; k++)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }

    // ── 9. OVERLOADED INDEXING OPERATOR [] ───────────────────
    //  Returns the row pointer so [][col] syntax works naturally.
    int* operator[](int rowIdx) {
        if (rowIdx < 0 || rowIdx >= rows)
            throw out_of_range("Row index out of range.");
        return data[rowIdx];
    }

    // Const version
    const int* operator[](int rowIdx) const {
        if (rowIdx < 0 || rowIdx >= rows)
            throw out_of_range("Row index out of range.");
        return data[rowIdx];
    }

    // ── UTILITY: print the array ──────────────────────────────
    void print(const string& label = "") const {
        if (!label.empty()) cout << label << ":\n";
        for (int i = 0; i < rows; i++) {
            cout << "  [ ";
            for (int j = 0; j < cols; j++)
                cout << data[i][j] << (j < cols - 1 ? ", " : " ");
            cout << "]\n";
        }
    }

    // Getters
    int getRows() const { return rows; }
    int getCols() const { return cols; }
};


// ─────────────────────────────────────────────────────────────
//  TEST PROGRAMME
// ─────────────────────────────────────────────────────────────
int main() {
    cout << "============================================================\n";
    cout << "        2D Dynamic Integer Array – Test Programme\n";
    cout << "============================================================\n\n";

    // ── Test 1: Default Constructor ───────────────────────────
    cout << "TEST 1: Default Constructor\n";
    Array2D empty;
    cout << "  Rows: " << empty.getRows() << ", Cols: " << empty.getCols() << "\n\n";

    // ── Test 2: Parameterised Constructor ─────────────────────
    cout << " TEST 2: Parameterised Constructor \n";
    Array2D A(3, 3);
    // Fill manually via indexing operator
    int val = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            A[i][j] = val++;
    A.print("Matrix A (1..9)");
    cout << "\n";

    Array2D B(3, 3);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            B[i][j] = (i == j) ? 2 : 1;   // 2 on diagonal, 1 elsewhere
    B.print("Matrix B (diagonal=2, rest=1)");
    cout << "\n";

    // ── Test 3: Copy Constructor ──────────────────────────────
    cout << " TEST 3: Copy Constructor\n";
    Array2D C(A);   // copy of A
    C.print("Matrix C (copy of A)");
    cout << "\n";

    // ── Test 4: Assignment Operator ───────────────────────────
    cout << "TEST 4: Assignment Operator \n";
    Array2D D(3, 3, 0);
    D = B;   // assign B to D
    D.print("Matrix D (assigned from B)");
    cout << "\n";

    // ── Test 5: Operator + ────────────────────────────────────
    cout << "TEST 5: Operator + (A + B) \n";
    Array2D sum = A + B;
    sum.print("A + B");
    cout << "\n";

    // ── Test 6: Operator - ────────────────────────────────────
    cout << "TEST 6: Operator - (A - B)\n";
    Array2D diff = A - B;
    diff.print("A - B");
    cout << "\n";

    // ── Test 7: Operator * (matrix multiplication) ────────────
    cout << " TEST 7: Operator * (A * B)\n";
    Array2D prod = A * B;
    prod.print("A * B");
    cout << "\n";

    // ── Test 8: Indexing Operator ─────────────────────────────
    cout << "TEST 8: Indexing Operator \n";
    cout << "  A[1][2] = " << A[1][2] << "  (expected: 6)\n";
    A[1][2] = 99;
    cout << "  After A[1][2] = 99:\n";
    A.print("  Modified A");
    cout << "\n";

    // ── Test 9: Self-assignment guard ─────────────────────────
    cout << " TEST 9: Self-assignment guard\n";
    B = B;
    B.print("Matrix B (unchanged after B = B)");
    cout << "\n";

    // ── Test 10: Error handling ───────────────────────────────
    cout << " TEST 10: Error Handling \n";
    try {
        Array2D X(2, 3, 1);
        Array2D Y(3, 2, 1);
        Array2D bad = X + Y;   // dimension mismatch
    } catch (const invalid_argument& e) {
        cout << "  Caught expected error: " << e.what() << "\n";
    }

    try {
        Array2D X(2, 3, 1);
        int v = X[5][0];      // row out of range
        (void)v;
    } catch (const out_of_range& e) {
        cout << "  Caught expected error: " << e.what() << "\n";
    }
    cout << "\n";

    // ── Destructors fire here as locals go out of scope ───────
    cout << " Destructors firing as locals leave scope \n";
    return 0;
}