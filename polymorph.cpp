#include <iostream>
using namespace std;

class Base {
    public:
    virtual void display() {
        cout << " Derived class function";
    }

};
class Derived : public Base{
    public:
    void display() override {
        cout << "Derived class function";
    }

};
int main() {
    Base *baseptr;
    Derived deriobj;
    baseptr = & deriobj;
    baseptr->display();
    return 0;
}