#include <cstdio>

//  Every C++ expression yield either an rvalue or an lvalue
//  If the expression has an identifiable memory address, it's lvalue
//  otherwise, rvalue - taken from BoQian's youtube tutorials on C++
using namespace std;

int global_int = 100;

//  rvalue misconception 1 - function always return rvalues
//  Proof - a function return a global variable - which is an lvalue
int& func() {
    return global_int;
}

//  arg int&x expects and lvalue
//  to make it work for both lvalue and rvalue arguments, we should
//  use the const reference exception case as below
//  then it works for both printX(x) and printX(100)
const int& printX(const int& x) {
    return x;
}

int main(int argc, char *argv[])
{
    int x = 10;

    printf("global_int = %d\n", global_int);
    func() = 400;
    printf("global_int = %d\n", global_int);

    printf("value of x = %d\n", printX(x));
    printf("2 is %d\n", printX(2));

    return 0;
}
