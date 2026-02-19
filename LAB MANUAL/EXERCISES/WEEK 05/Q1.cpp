#include<iostream>
using namespace std;
class Base{
    private:
        int privateInt;
    public:
        int publicInt;
    protected:
        int protectedInt;

     void setPrivateInt(int x) {
        privateInt = x;
    }
    void setProtectedInt(int x) {
        protectedInt = x;
    }
    void setPublicInt(int x) {
        publicInt = x;
    }

    int getPrivateInt() {
        return privateInt;
    }
    int getProtectedInt() {
        return protectedInt;
    }
    int getPublicInt() {
        return publicInt;
    }
};
class protectedChild : protected Base{
public:
    void showAccess() {
        cout << "Protected Inheritance:" << endl;
        cout << "protectedInt accessed directly: " << protectedInt << endl;
        cout << "publicInt accessed directly: " << publicInt << endl;
        cout << "privateInt via getter: " << getPrivateInt() << endl;
    }

};
class publicChild : public Base {
public:
    void showAccess() {
        cout << "Public Inheritance:" << endl;
        cout << "protectedInt accessed directly: " << protectedInt << endl;
        cout << "publicInt accessed directly: " << publicInt << endl;
        cout << "privateInt via getter: " << getPrivateInt() << endl;
    }
};
class privateChild : private Base{
public:
    void showAccess() {
        cout << "Private Inheritance:" << endl;
        cout << "protectedInt accessed directly: " << protectedInt << endl;
        cout << "publicInt accessed directly: " << publicInt << endl;
        cout << "privateInt via getter: " << getPrivateInt() << endl;
    }
};
int main(){
    publicChild pc;
    pc.setPrivateInt(10);
    pc.setProtectedInt(20);
    pc.setPublicInt(30);
    pc.showAccess();

    cout << endl;

    protectedChild prc;
    prc.setPrivateInt(40);
    prc.setProtectedInt(50);
    prc.setPublicInt(60);
    prc.showAccess();

    cout << endl;

    privateChild prvc;
    prvc.setPrivateInt(70);
    prvc.setProtectedInt(80);
    prvc.setPublicInt(90);
    prvc.showAccess();

    return 0;
}