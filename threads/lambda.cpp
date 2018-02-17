#include <iostream>
#include <thread>

using namespace std;

int main()
{
    int n = 1;
    int it = 10;

    //  thread initialization with lambda function
    thread t([n, it] {
        for (int i = 0; i < it; i++) {
            cout << "Counter " << n << " has value " << i << endl;
        }
    });

    t.join();

    return 0;
}
