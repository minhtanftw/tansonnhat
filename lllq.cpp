#include <iostream>
#include <cassert>

using namespace std;

int divide(int a, int b)
{
    assert(b != 0);   // kiểm tra b khác 0
    return a / b;
}

int main()
{
    int x = 10;
    int y = 2;

    int result = divide(x, y);
    cout << "Result = " << result << endl;

    return 0;
}