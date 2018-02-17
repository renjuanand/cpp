#include <iostream>
#include <string>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

class Logger {
public:
    Logger();

    //  Prevent copy construction and assignment.
    Logger(const Logger& src) = delete;
    Logger& operator=(const Logger& src) = delete;

    //  Add log entry to the queue
    void log(const std::string& entry);

private:
    void processEntries();
    mutex _mutex;
    condition_variable _cond;
    queue<string> _queue;
    //  background thread 
    thread _thread;
};

Logger::Logger() {
    _thread = thread{ &Logger::processEntries, this};
}

void Logger::log(const string& entry) {

}

void Logger::processEntries() {
    ofstream ofs("log.txt");
}

int main(int argc, char *argv[])
{

    return 0;
}
