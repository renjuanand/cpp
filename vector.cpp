#include <iostream>
#include <vector>

using namespace std;

void print_vector(const vector<int> &v) {
    for (auto &i : v) {
        cout << i << " ";
    }

    cout << endl;
}

int main(int argc, char *argv[])
{
    vector<int> vi = {1, 2, 3, 4, 5};

    for (vector<int>::iterator i = vi.begin(); i < vi.end(); i++) {
        cout << *i << " ";
    }

    cout << endl;
    print_vector(vi);

    vi.insert(vi.begin() + 2, 20);
    print_vector(vi);

    vi.push_back(50);
    print_vector(vi);

    cout << "size: " << vi.size() << endl;
    cout << "element at 3 is " << vi[3] << endl;
    cout << "element at 3 is " << vi.at(3) << endl;

    vi.erase(vi.begin() + 2);
    print_vector(vi);
    return 0;
}
