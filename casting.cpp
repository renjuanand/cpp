#include <iostream>

using namespace std;

void func(int& x) {
    x = 222;
    cout << "x: " << x << endl;
}

class X {};
class Y {};

class Base {
public:
    Base() {}
    virtual ~Base() {}
};

class Derived : public Base {
public:
    Derived() {}
    virtual ~Derived() {}
};


int main()
{
    const int xx = 111;

    cout << "xx: " << xx << endl;
    //  const_cast to cast away the const-ness of a variable.
    func(const_cast<int&>(xx));

    cout << "xx: " << xx << endl;

    int i = 4;
    int j = 5;

    double r = static_cast<double>(i) / j;

    //  reinterpret_cast
    //  cast a reference to one type to another type, even if the types are unrelated
    //  Similarly, cast a pointer to one type to another pointer type, even if they are
    //  unrelated by an inheritance hierarchy.
    X x;
    Y y;

    X* xp = &x;
    Y* yp = &y;

    xp = reinterpret_cast<X*>(yp);
    void *p = xp;
    xp = reinterpret_cast<X*>(p);

    X& xr = x;
    Y& yr = reinterpret_cast<Y&>(x);

    Base b;
    Derived d;
    Base& br = b;

    return 0;
}
