#include <iostream>
using namespace std;

class Base{
    public:
    virtual void display(){
        cout << "Base clas function";
    }

};

class Derived : public Base{
    public:
    void display() override{
        cout << "Derived class function";
    }
};

int main() {
    Base* baseptr;
    Derived derived;
    baseptr = &derived;
    baseptr->display();
    return 0;

}