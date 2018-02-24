#include <iostream>
#include <functional>

using namespace std;

void executeFunc(std::function<void()> f) {
    f();
}

int main()
{
    int x = 10;

    auto compute = [&]() -> void {
        ++x;
    };

    executeFunc(compute);
    cout << "x: " << x << endl;

    executeFunc(compute);
    cout << "x: " << x << endl;

    return 0;
}
