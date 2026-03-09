#include <iostream>

using namespace std;

int square(int x) {
    return x *x ;
}

void process(int value, int (*func)(int)) {
    cout << "Result" << func(value);
}

int main() {
    process(5,square);
    return 0;
}