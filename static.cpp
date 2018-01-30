#include <cstdio>

using namespace std;

class Foo {
private:
    //  non-const static data member must be initialized out of line
    static int foo;

    //  const static can be initialized inside the class
    static const int xyz = 200;
public:
    void print() {
        printf("foo is %d\n", foo);
        printf("xyz is %d\n", xyz);
    }

    void incFoo() {
        ++foo;
    }
};

int Foo::foo = 100;

int main(int argc, char *argv[])
{
    Foo f1, f2;

    f1.print();
    f2.print();

    f1.incFoo();

    f1.print();
    f2.print();

    return 0;
}
