#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
    const int bufSize = 1024;
    char buf[bufSize];

    fputs("Enter something: ", stdout);
    fflush(stdout);
    fgets(buf, bufSize, stdin);
    fputs(buf, stdout);

    return 0;
}
