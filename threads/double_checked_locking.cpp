#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>

using namespace std;

atomic<bool> initialized(false);
mutex mu;

void initializeSharedResource() {
    cout << "shared resource initialized" << endl;
}

void threadFunc() {
    //  double checking of initialized should be avoided using call_once
    if (!initialized) {
        unique_lock<mutex> lock(mu);

        if (!initialized) {
            initializeSharedResource();
            initialized = true;
        }
    }

    cout << "threadFunc Done" << endl;
}

int main()
{
    vector<thread> threads;

    for (int i = 0; i < 10; i++) {
        threads.push_back(thread{ threadFunc });
    }

    for (auto& t : threads) {
        t.join();
    }
    return 0;
}
