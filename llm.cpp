#include <iostream>
using namespace std;

int fun(int ptr[]) {
    int x = 10;
    cout << "sizeof(ptr) ="
        << (int)sizeof(*ptr)
        << endl;
    ptr = &x;
    cout << "*ptr =" << *ptr;
    return 0;
}
int main() {
    int arr[] = { 20, 20,10,30,40,50, 60};
    cout << "sizeofarr = "
         <<(int)sizeof(arr)
         <<endl;
    fun(arr);
    return 0;
}