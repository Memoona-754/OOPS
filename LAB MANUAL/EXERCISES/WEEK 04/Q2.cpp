#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int currentSize;   

public:

    // Parameterized Constructor
    DynamicArray(int size) {
        currentSize = size;
        arr = new int[currentSize];

        // Initialize all values to 0
        for (int i = 0; i < currentSize; i++) {
            arr[i] = 0;
        }
    }

    // Destructor
    ~DynamicArray() {
        delete[] arr;
    }

    // Push function
    void push(int value) {

        // Create new array with size + 1
        int* newArr = new int[currentSize + 1];

        // Copy old values
        for (int i = 0; i < currentSize; i++) {
            newArr[i] = arr[i];
        }

        // Add new value at end
        newArr[currentSize] = value;

        // Delete old memory
        delete[] arr;

        // Update pointer
        arr = newArr;

        // Increase size
        currentSize++;
    }

    // size() function
    int size() const {
        return currentSize;
    }

    // Display function (for testing)
    void display() const {
        for (int i = 0; i < currentSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {

    DynamicArray obj(3);

    cout << "Initial array: ";
    obj.display();

    obj.push(10);
    obj.push(20);

    cout << "After pushing values: ";
    obj.display();

    cout << "Size of array: " << obj.size() << endl;

    return 0;
}