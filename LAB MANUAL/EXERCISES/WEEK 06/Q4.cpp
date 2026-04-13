//CT_25166            //MEMOONA
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    string occupation;

public:
    Person(string _occupation) : occupation(_occupation), name("Unknown") {}

    virtual void Draw() {
        cout << "A person can draw in many ways\n";
    }

    // Virtual destructor(essential when deleting via base pointer)
    virtual ~Person() {}
};

class Artist : public Person {
public:
    Artist() : Person("artist") {}

    void Draw() override {
        cout << "An artist can draw with a paint brush\n";
    }
};

class Gunman : public Person {
public:
    Gunman() : Person("gunman") {}

    void Draw() override {
        cout << "A gunman draws a gun to shoot\n";
    }
};

int main() {
    const int SIZE = 3;

    // Array of base-class pointers
    Person* people[SIZE];

    // Dynamically create one of each type
    people[0] = new Person("person");
    people[1] = new Artist();
    people[2] = new Gunman();

    cout << "Calling Draw() for each object:\n";

    // Polymorphic dispatch — correct Draw() called for each type
    for (int i = 0; i < SIZE; i++) {
        people[i]->Draw();
    }


    // Clean up heap memory
    for (int i = 0; i < SIZE; i++) {
        delete people[i];
    }

    return 0;
}