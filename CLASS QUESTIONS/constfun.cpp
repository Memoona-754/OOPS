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
        return radius;
    }
};

int main()
{
    Circle c1(5);
    cout << "Radius: " << c1.getRadius() << endl;

    return 0;
}
