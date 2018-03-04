#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
    map<string, string> m = { { "George", "Father" }, { "Liza", "Mother" },
                              { "Linda", "Daughter" } };

    for (auto& p : m) {
        cout << p.first << " : " << p.second << endl;
    }

    auto rp = m.insert( {"Ben", "Neighbour"} );

    if (rp.second) {
        cout << "insert succeeded: { " << rp.first->first << ", " << rp.first->second << " }" << endl;
    } else {
        cout << "insert failed: { " << rp.first->first << ", " << rp.first->second << " }" << endl;
    }

    rp = m.insert( {"Ben", "Neighbour"} );

    if (rp.second) {
        cout << "insert succeeded: { " << rp.first->first << ", " << rp.first->second << " }" << endl;
    } else {
        cout << "insert failed: { " << rp.first->first << ", " << rp.first->second << " }" << endl;
    }

    auto it = m.find("Linda");

    if (it != m.end()) {
        m.erase(it);
    }

    for (auto& p : m) {
        cout << p.first << " : " << p.second << endl;
    }

    cout << "map size: " << m.size() << endl;

    return 0;
}
