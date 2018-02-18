//  std::timed_mutex example

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
using namespace std;

class Counter {
public:
    Counter(int n, int it) : _n(n), _it(it) { }
    void operator()() const {
        for (int i = 0; i < _it; i++) {
            unique_lock<timed_mutex> lock(_mu, chrono::milliseconds(1));
            if (lock) {
                cout << "Counter " << _n << " has value: " << i << endl;
            } else {
                //  this defeats the purpose here anyway
                cout << "Counter " << _n << " couldn't aquire mutex in 1 milliseconds" << endl;
            }
        }
    }
private:
    int _n;
    int _it;
    static timed_mutex _mu;
};

timed_mutex Counter::_mu;

int main()
{
    vector<thread> threads(10);
    int i = 1;
    for (auto& t : threads) {
        t = thread { Counter{ i++, 10 } };
    }
    
    for (auto& t : threads) {
        t.join();
    }
    return 0;
}
