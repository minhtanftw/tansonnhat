#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    q.push(10);
    q.push(1212);
    q.pop();

    cout << "Front Elements" << q.front() << endl;
    cout << "Back Elemenents" << q.back() << endl;

    q.pop();
    cout << "Front Element after pop " << q.front() << endl;
    return 0;
}