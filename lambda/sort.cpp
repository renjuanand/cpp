#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;

    Point() {
        x = (rand() % 10000) - 5000;
        y = (rand() % 10000) - 5000;
    }

    void printPoint() {
        cout << "[" << x << ", " << y << "]" << endl;
    }
};

int main()
{
    vector<Point> points(5);

    cout << "Unsorted points" << endl;
    for (auto p : points) {
        p.printPoint();
    }

    sort(begin(points), end(points), [](const Point& p, const Point& q) -> bool {
        return (p.x * p.x) + (p.y * p.y) < (q.x * q.x) + (q.y * q.y);
    });

    cout << "Sorted points" << endl;
    for (auto p : points) {
        p.printPoint();
    }
    return 0;
}
