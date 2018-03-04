#include <iostream>
#include <string>
#include <stack>
#include <list>

using namespace std;

int main(int argc, char *argv[])
{
    list<string> l = { "Thomas", "Martin", "Eva", "Edan" };    
    stack<string, list<string>> s(l);

    cout << "size of stack: " << s.size() << endl;

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    cout << "size of stack: " << s.size() << endl;

    stack<int> si;

    si.push(11);
    si.push(22);
    si.push(33);
    si.push(44);

    while (!si.empty()) {
        cout << si.top() << endl;
        si.pop();
    }

    return 0;
}
