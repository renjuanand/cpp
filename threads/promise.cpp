#include <iostream>
#include <functional>
#include <thread>
#include <future>
#include <chrono>

using namespace std;

void printInt(future<int>& f) {
    cout << "Waiting result from main thread" << endl;
    int val = f.get();
    cout << "value: " << val << endl;
}

int main()
{
    promise<int> p;
    future<int> f = p.get_future();

    thread th(printInt, std::ref(f)); //  send future to new thread

    this_thread::sleep_for(chrono::seconds(1));
    p.set_value(10);
    cout << "Set the value for promise in main thread" << endl;

    th.join();

    return 0;
}
