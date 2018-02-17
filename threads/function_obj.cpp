#include <iostream>
#include <thread>

using namespace std;

class Counter {
public:
    Counter(int n, int it) : _n(n), _it(it) { }

    void operator()() {
        for (int i = 0; i < _it; i++) {
            cout << "Counter " << _n << " has value " << i << endl;
        }
    }
private:
    int _n, _it;
};

int main()
{
    //  thread initialization with function object
    thread t1{ Counter{1, 10} };
    t1.join();

    Counter c(2, 10);
    thread t2(c);
    t2.join();

    thread t3((Counter(3, 10)));

    t3.join();

    return 0;
}
