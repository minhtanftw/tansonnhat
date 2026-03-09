#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {1,4,3,3,3,54,3};
    auto it = find(v.begin(), v.end(), 22);
    if (it != v.end()) {
        cout << distance(v.begin(),it);

    }
    else{
        cout << " Not present";
    }
    return 0;

}