#include <iostream>
using namespace std;

class foo
{
private:
    static int count;  // declaration only

public:
    foo()
    {
        count++;  // increments when object created
    }

    int getcount()
    {
        return count;  // returns count
    }
};

// definition of count
int foo::count = 0;

int main()
{
    foo f1, f2, f3;  // create three objects

    cout << "count is " << f1.getcount() << endl;  // each object
    cout << "count is " << f2.getcount() << endl;  // sees the
    cout << "count is " << f3.getcount() << endl;  // same value

    return 0;
}
