#include <iostream>
#include <tuple>
#include <string>

using namespace std;

int main()
{
    pair<int, string> p = make_pair(25, "Hello");

    cout << p.first << " " << p.second << endl;

    tuple<string, string, int> person = make_tuple("Ryan", "Ren", 5);

    cout << get<0>(person) << endl;
    cout << get<1>(person) << endl;
    cout << get<2>(person) << endl;

    string fName, sName;
    int age;

    make_tuple(ref(fName), ref(sName), ref(age)) = person;

    string &s = get<0>(person);

    typedef tuple<int, string, char> T;
    T t1;
    T t2;

    t1 = tuple<int, string, char>(10, "Animal", 'a');
    t2 = make_tuple(20, "Bird", 'b');

    if (t1 == t1) {
        cout << "t1 and t2 are same" << endl;
    }

    int x;
    string y;
    char z;

    std::tie(x, y, z) = t1;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "z: " << z << endl;

    std::tie(x, std::ignore, z) = t2;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "z: " << z << endl;

    auto t3 = tuple_cat(person ,t1);

    cout << std::tuple_size<decltype(t3)>::value << endl;  // 6 
    std::tuple_element<1, decltype(t3)>::type n; // n is string

    n = get<0>(t3);
    cout << get<1>(t3) << endl;
    cout << n << endl;

    return 0;
}
