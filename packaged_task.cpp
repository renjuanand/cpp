#include <iostream>
#include <string>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <deque>
#include <vector>
#include <chrono>

using namespace std;

std::mutex mu;
std::condition_variable cond;
std::deque<std::packaged_task<int()>> task_q;

long compute_sum(int x) {
    int result = 0;
    for (int i = 0; i < x; i++, result += i);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "sum: " << result << endl;

    return result;
}

//  thread function which runs the task items
void task_runner() {
    std::packaged_task<int()> task;

    while (!task_q.empty()) {
        {
        std::unique_lock<std::mutex> locker(mu);
        cond.wait(locker, []() { return !task_q.empty(); });
        task = std::move(task_q.front());
        task_q.pop_front();
        }

        //  run the task
        task();
    }
}

int main(int argc, char *argv[])
{
    //  child thread which runs the task items
    std::thread t1(task_runner);

    //  vector to store future objects
    std::vector<std::future<int>> fut_vector;

    //  create some tasks and give to task_runner(child thread) to execute
    //  and return the results

    for (int i = 1; i <= 5; i++) {
        std::packaged_task<int()> task = std::packaged_task<int()>(std::bind(compute_sum, i));
        fut_vector.push_back(task.get_future());

        {
            std::lock_guard<std::mutex> locker(mu);
            task_q.push_back(std::move(task));
        }
        cond.notify_all();
    }

    //  sleep main thread for 3 seconds, while our task runner may
    //  run some tasks for us
    cout << "main thread sleeping for 3 seconds" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));

    cout << "main thread done his job" << endl;
    cout << "lets see results from task runner thread" << endl;

    //  get the results from future objects
    for (auto &f: fut_vector) {
        cout << "result: "<< f.get() << endl;
    }

    t1.join();
    return 0;
}
