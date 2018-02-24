#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1 = "This is a string";

    cout << "Length of string s1 = " << s1.size() << endl;
    cout << "Length of string s1 = " << s1.length() << endl;

    s1.insert(s1.begin() + 5, 'X');
    cout << s1 << endl;

    s1.erase(s1.begin() + 5);
    cout << s1 << endl;

    s1.replace(8, 1, "not ");
    cout << s1 << endl;

    size_t pos =  s1.find("s");

    cout << "position of last s: " << pos << endl;
    pos = s1.rfind("s");
    cout << "position of last s: " << pos << endl;

    return 0;
}
