#include <iostream>
#include <cstdio>
#include <typeinfo>

extern "C" {
#include "test.h"
}

using namespace std;

int main(int argc, char ** argv)
{
    func();

    return 0;
}
