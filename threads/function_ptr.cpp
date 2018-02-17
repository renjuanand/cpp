#include <iostream>
#include <thread>

using namespace std;

void counter(int n, int it) {

    for (int i = 0; i < it; i++) {
        cout << "Counter " << n << " has value " << i << endl;
    }
}

int main()
{
    //  thread initialization with fn pointer
    thread t{ counter, 1, 10 };

    t.join();

    return 0;
}
