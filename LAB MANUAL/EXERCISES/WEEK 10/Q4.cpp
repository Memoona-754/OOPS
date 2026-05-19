#include <iostream>
using namespace std;

// Abstract Class Template for 1D Dynamic Array
template <class T>
class DynamicArray
{
protected:
    T* arr;
    int capacity;

public:
    DynamicArray(int size = 5)
    {
        capacity = size;
        arr = new T[capacity];
    }

    virtual bool isFull() = 0;
    virtual bool isEmpty() = 0;
    virtual int size() = 0;
    virtual T Front() = 0;
    virtual T Rear() = 0;
    virtual void enqueue(T value) = 0;
    virtual void dequeue() = 0;
    virtual void resize() = 0;

    virtual ~DynamicArray()
    {
        delete[] arr;
    }
};

// Dynamic Queue Class
template <class T>
class DynamicQueue : public DynamicArray<T>
{
private:
    int front;
    int rear;
    int count;

public:
    DynamicQueue(int size = 5) : DynamicArray<T>(size)
    {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isFull()
    {
        return count == this->capacity;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    int size()
    {
        return count;
    }

    T Front()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return -1;
        }

        return this->arr[front];
    }

    T Rear()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return -1;
        }

        return this->arr[rear];
    }

    void resize()
    {
        int newCapacity = this->capacity * 2;

        T* newArr = new T[newCapacity];

        for (int i = 0; i < count; i++)
        {
            newArr[i] = this->arr[(front + i) % this->capacity];
        }

        delete[] this->arr;

        this->arr = newArr;
        this->capacity = newCapacity;

        front = 0;
        rear = count - 1;

        cout << "Queue Resized to " << newCapacity << endl;
    }

    void enqueue(T value)
    {
        if (isFull())
        {
            resize();
        }

        rear = (rear + 1) % this->capacity;
        this->arr[rear] = value;
        count++;

        cout << value << " inserted into queue\n";
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow\n";
            return;
        }

        cout << this->arr[front] << " removed from queue\n";

        front = (front + 1) % this->capacity;
        count--;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Queue Elements: ";

        for (int i = 0; i < count; i++)
        {
            cout << this->arr[(front + i) % this->capacity] << " ";
        }

        cout << endl;
    }
};

int main()
{
    DynamicQueue<int> q(5);

    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);

    q.display();

    q.enqueue(8); // triggers resize

    q.display();

    cout << "Front Element: " << q.Front() << endl;
    cout << "Rear Element: " << q.Rear() << endl;

    q.dequeue();
    q.dequeue();

    q.display();

    cout << "Current Size: " << q.size() << endl;

    return 0;
}