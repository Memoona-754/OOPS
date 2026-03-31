#include <iostream>
using namespace std;

class Circle
{
private:
    int radius;

public:
    Circle(int r)
    {
        radius = r;
    }

    // constant member function
    int getRadius() const
    {
        radius =10;
        return radius;
    }
};

int main()
{
    Circle c1();
    cout << "Radius: " << c1.getRadius() << endl;

    return 0;
}
