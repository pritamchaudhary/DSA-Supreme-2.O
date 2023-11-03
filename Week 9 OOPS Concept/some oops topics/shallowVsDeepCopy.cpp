// shallow vs deep copy

#include <iostream>
using namespace std;

class abc
{
public:
    int x;
    int *y;

    abc(int _x, int _y) : x(_x), y(new int(_y)) {}

    // default dump copy constructor : it does SHALLOW COPY
    // abc(const abc &obj)
    // {
    //     x = obj.x;
    //     // y = obj.y;
    // }

    // our smart DEEP COPY
    abc(const abc &obj)
    {
        x = obj.x;
        y = new int(*obj.y);
    }

    void print() const
    {
        printf("X: %d\nPTR Y: %p\nContent of Y (*y):%d\n\n", x, y, *y);
    }
};

int main()
{
    abc a(1, 3);
    cout << "Printing a\n";
    a.print();

    abc b = a; // call hota hai , copy constructor
    cout << "Printing b\n";
    b.print();
    *b.y = 20;
    cout << "Printing b\n";
    b.print();

    cout << "Printing a\n";
    a.print();

    return 0;
}