#include <iostream>
#include <vector>
#include <algorithm>

//  example using for_each algorithm & lambda
using namespace std;

int main()
{
    vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int sum = 0;

    //  for_each using lambda function
    for_each(begin(v), end(v), [&](int x) {
        sum += x;
    });

    cout << "vector sum: " << sum << endl;
    return 0;
}
