#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
T Max(vector<T>& v) {
    if (v.empty()) {
        throw std::runtime_error("vector empty");
    }
    T res = v[0];

    for (typename std::vector<T>::iterator it = v.begin(); it != v.end(); ++it) {
        if (*it > res) {
            res = *it;
        }
    }

    return res;
}

int main()
{
    vector<int> v = { 1, 23, 10, 20, 100, 235, 12, 233};

    cout << Max(v) << endl;

    vector<int> v2;

    cout << Max(v2) << endl;
    return 0;
} 
