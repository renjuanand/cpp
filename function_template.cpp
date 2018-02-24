#include <iostream>

using namespace std;

template<typename T>
T myMin(const T& x, const T& y) {
    return (x < y) ? x : y;
}

int main()
{
    double a = 10.23;
    double b = 210.21;

    int x = 429;
    int y = 124;

    cout << myMin(a, b) << endl;
    cout << myMin(x, y) << endl;

    int p = 450;
    float q = 234.29;

    cout << myMin<float>(p, q) << endl;
    return 0;
}
