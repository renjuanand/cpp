#include <iostream>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

class Counter {
public:
    Counter(int n, int it) : _n(n), _it(it) { }
    void operator()() const {
        for (int i = 0; i < _it; i++) {
            lock_guard<mutex> lock(_mu);
            cout << "Counter " << _n << " has value: " << i << endl;
        }
    }
private:
    int _n;
    int _it;
    static mutex _mu;
};

mutex Counter::_mu;

int main()
{
    thread t1 { Counter{ 1, 10 } };
    thread t2((Counter(2, 10)));

    t1.join();
    t2.join();
    return 0;
}
