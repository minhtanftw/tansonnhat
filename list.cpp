#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> myList;
    myList.push_back(10);
    myList.push_back(211);
    myList.push_back(21);
    cout << " list element";
    for (int n : myList) {
        cout << n << " ";
    }
    cout << endl;
}