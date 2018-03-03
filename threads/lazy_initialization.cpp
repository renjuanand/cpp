#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <mutex>
#include <sstream>

using namespace std;

class LogFile {
    mutex _mu;
    once_flag _flag;
    ofstream _f;
public:
    LogFile() = default;

    void sharedPrint(const string& id, const int& value) {
        call_once(_flag, [&]() {
            _f.open("logfile.txt");
        });

        unique_lock<mutex> locker(_mu, std::defer_lock);
        locker.lock();
        _f << "From: " << id << ": " << value << endl;
        locker.unlock();
    }

    ~LogFile() {
        _f.close();
    }
};

int main()
{
    LogFile lf;

    thread t1([&]() {
        stringstream ss;
        ss << this_thread::get_id();
        lf.sharedPrint(ss.str(), 1000);
    });

    thread t2([&]() {
        stringstream ss;
        ss << this_thread::get_id();
        lf.sharedPrint(ss.str(), 2000);
    });

    t1.join();
    t2.join();

    return 0;
}
