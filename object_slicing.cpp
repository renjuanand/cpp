// Object slicing happens when a derived class object is
// assigned to a base class object, additional attributes
// of a derived class object are sliced off to form the
// base class object.

class Base {
    int a;
    int b;
};

class Derived : public Base {
    int c;
    int d;
};


//  Object slicing doesn’t occur when pointers or references
//  to objects are passed as function arguments since a pointer
//  or reference of any type takes same amount of memory. 

int main()
{
    Derived d;
    Base b = d; //  Object slicing, c and d of d object are sliced off

    return 0;
}
