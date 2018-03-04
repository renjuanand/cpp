#include <iostream>
#include <string>
#include <queue>
#include <list>

using namespace std;

int main(int argc, char *argv[])
{
    list<string> l = { "Thomas", "Martin", "Eva", "Edan" };    
    //  queue is container adaptor
    queue<string, list<string>> q(l);

    cout << "size of queue: " << q.size() << endl;

    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }

    cout << "size of queue: " << q.size() << endl;

    queue<int> qi;
    qi.push(11);
    qi.push(22);
    qi.push(33);
    qi.push(44);

    while (!qi.empty()) {
        cout << qi.front() << endl;
        qi.pop();
    }

    return 0;
}
