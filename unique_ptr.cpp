#include <iostream>
#include <string>
#include <memory>

//  unique_ptr example:
//  unique_ptr is for exclusive ownership, light weight smart pointer

using namespace std;

class Dog {
private:
    string _name;
public:
    Dog() : _name("") {
        cout << "dog created" << endl;
    }
    Dog(string name) : _name(name) {
        cout << "dog " << _name << " created" << endl;
    }
    void bark() {
        cout << _name << " barks" << endl;
    }
    ~Dog() {
        cout << "dog " << _name << " destroyed" << endl;
    }
};

class Pet {
    unique_ptr<Dog> dog;
public:
    //  unique_ptr should be initialized using member initializer-list
    //  or use make_unique in C++14
    explicit Pet(string name) : dog(new Dog(name)) {
        cout << "Pet created" << endl;
        throw;
    }

    void action() {
        dog->bark();
    }

    ~Pet() {
        cout << "Pet destroyed" << endl;
    }
};


void f(unique_ptr<Dog> d) {
    d->bark();
    //  d is destroyed here in this function
}

unique_ptr<Dog> getDog() {
    unique_ptr<Dog> d(new Dog("tippu"));
    return d;
}

int main(int argc, char *argv[])
{
    unique_ptr<Dog> d1(new Dog("tommy"));

    //  release never destroys the object
    //d1.release();

    d1.reset(new Dog("Puppy"));

    unique_ptr<Dog> d2(new Dog("Ben"));
    d2->bark();

    d2 = std::move(d1);
    d2->bark();

    f(std::move(d2));

    if (!d2) {
        cout << "d2 is empty" << endl;
    }

    unique_ptr<Dog> d3 = getDog();

    // array of unique ptrs
    unique_ptr<Dog[]> dogs(new Dog[5]); 

    unique_ptr<Pet> p(new Pet("Alex"));
    p->action();

    return 0;
}   
