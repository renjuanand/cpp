
//  Define a class that has only one instance that globally exists
//  - global access
//  - one instance
//  - no ownership
//

//  Advantages:
//  - save memory - not creating many objects, only one instance
//  - single access point - eg: logger
//  - flexibility - change anytime you want

//  Usages:
//  - multithreaded - thread pool
//  - database application - connection, logging
//  - logging in an application
//  - configuration settings of an application

#include <iostream>
using namespace std;

class Singleton {
private:
    static Singleton* _instance;
    Singleton() {}
    Singleton(const Singleton& s) {}
    Singleton& operator=(const Singleton& s) {}

    int data;
public:
    //  not thread-safe
    static Singleton* getInstance() {
        if (_instance == nullptr) {
            _instance = new Singleton();
        }

        return _instance;
    }

    void setData(int val) {
        data = val;
    }

    int getData() const {
        return data;
    }
};

Singleton* Singleton::_instance = nullptr;

int main()
{
    Singleton* s = Singleton::getInstance();

    s->setData(111);
    cout << s->getData() << endl;

    Singleton* s2 = Singleton::getInstance();
    s2->setData(222);

    cout << s->getData() << endl;
    cout << s2->getData() << endl;
    
    return 0;
}
