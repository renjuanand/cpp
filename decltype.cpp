#include <cstdio>
#include <string>
#include <typeinfo>
using namespace std;

template <typename lhsT, typename rhsT>
auto typeInfer(lhsT &lhs, rhsT &rhs) -> decltype(lhs + rhs) {
    return lhs + rhs;
}

int main(int argc, char *argv[])
{
    const char *cstr = "c string";
    string str = "string class string";

    printf("type of cstr = %s\n", typeid(cstr).name());
    printf("type of str = %s\n", typeid(str).name());

    auto r = typeInfer<const char*, string>(cstr, str);
    printf("type of r = %s\n", typeid(r).name());

    int x = 10;
    double y = 3.1456;
    auto v = typeInfer<int, double>(x, y);
    printf("type of v = %s\n", typeid(v).name());
    return 0;
}
