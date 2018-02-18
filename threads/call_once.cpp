#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

once_flag gOnceFlag;

void doInitialize() {
    cout << "Initialing.." << endl;
}

void doProcess() {
    call_once(gOnceFlag, doInitialize);
    cout << "Processing..." << endl;
}

int main()
{
    vector<thread> threads(5);

    for (auto& t : threads) {
        t = thread{ doProcess };
    }

    for (auto& t : threads) {
        t.join();
    }
    return 0;
}
