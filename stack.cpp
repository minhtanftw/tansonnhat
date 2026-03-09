#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {1,2,3,4,5,6,7};
    cout << "Forward iteration";
    for(auto it = vec.begin(); it != vec.end(); it ++) {
        cout << *it <<endl;
    }
    cout <<"Forward read-only iteration";
    for(auto it = vec.cbegin(); it !=vec.end(); it ++){
        cout << *it << endl;
    }
    cout << "Reverse iteration";
    for (auto it = vec.rbegin(); it != vec.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}