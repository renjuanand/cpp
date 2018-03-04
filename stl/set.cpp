#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{
    set<string> s = { "Three", "Four", "One", "Five", "Two", "Six" };

    cout << "size of set: " << s.size() << endl;

    for (const string&str : s) {
        cout << str << " ";
    }
    cout << endl;

    set<string>::iterator it = s.find("Six");

    if (it != s.end()) {
        s.erase(it);
    }

    for (const string&str : s) {
        cout << str << " ";
    }
    cout << endl;

    auto rp = s.insert("Eight");
    if (rp.second) {
        cout << "insert succeeded: " << *rp.first << endl;
    } else {
        cout << "insert failed: " << *rp.first << endl;
    }

    rp = s.insert("Eight");
    if (rp.second) {
        cout << "insert succeeded: " << *rp.first << endl;
    } else {
        cout << "insert failed: " << *rp.first << endl;
    }

    for (const string&str : s) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}
