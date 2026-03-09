#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    /*
    vector<int> v = { 1,2,3,4,56,7,32,25,2};
    sort(v.begin(), v.end());
    auto it = unique(v.begin(), v.end());
    v.erase(it, v.end());
    for (auto &i :v) {
        cout << i << endl;
        
    }
    return 0;
    */

    int arr[5]= {4,2,3,5,32};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    sort(arr, arr+n);
    cout << arr[k-1];
    return 0;
}