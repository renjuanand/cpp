#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    //  Compile time assert (C++11)

    static_assert(sizeof(int) == 4);

    return 0;
}
