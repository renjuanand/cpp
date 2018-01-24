#include <cstdio>
#include <string>
using namespace std;

template <typename T>
T maxof(T a, T b) {
    return (a > b ? a : b);
}

int main(int argc, char *argv[])
{
    printf("max: %d\n", maxof<int>(10, 30));
    printf("max: %s\n", maxof<string>("hello", "abcd").c_str());
    return 0;
}
