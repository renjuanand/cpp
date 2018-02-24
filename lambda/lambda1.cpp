#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    //  simple lambda function
    auto helloWorld = []() -> void {
        cout << "Hello world!" << endl;
    };

    helloWorld();

    //  lambda with arguments
    auto sum = [](int x, int y) -> int {
        return x + y;
    };

    cout << "sum: " << sum(10, 20) << endl;

    //  capture list => capture by value
    int a = 100, b = 200;

    //  we cannot the change the value of a & b
    //  as those are being captured by value
    //  compiler is smart enough to throw the
    //  error: cannot assign to a variable captured by copy in a non-mutable lambda
    //  To avoid this compiler error, mutable keyword is added
    auto change = [a, b]() mutable -> void {
        cout << "a: " << a << ", b: " << b << endl;
        a = b = 300;
    };

    change();
    cout << "a: " << a << ", b: " << b << endl;

    //  capture list => capture by reference
    string name = "anonymous";
    auto changeName = [&name]() -> void {
        name = "foo";
    };

    changeName();
    cout << "name: " << name << endl;

    //  capture all by value
    auto allByValue = [=]() -> void {
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
        cout << "name: " << name << endl;
        cout << "sum: " << sum(200, 400) << endl;
    };

    allByValue();

    //  capture all by reference
    auto allByRef = [&]() -> void {
        a = b = 500;
        name = "bar";
    };

    allByRef();
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "name: " << name << endl;

    return 0;
}
