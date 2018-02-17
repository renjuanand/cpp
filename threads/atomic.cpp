#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
#include <chrono>

using namespace std;

void func(atomic<int>& c) {
    int result = 0;
    for (int i = 0; i < 100; i++) {
        ++result;
        this_thread::sleep_for(chrono::milliseconds(1));
    }
    c += result;
}

int main()
{
    atomic<int> count(0);
    vector<thread> threads;

    for (int i = 0; i < 10; i++) {
        threads.push_back(thread{ func, std::ref(count) });
    }

    for (auto& t: threads) {
        t.join();
    }

    cout << "count: " << count << endl;
    return 0;
}
