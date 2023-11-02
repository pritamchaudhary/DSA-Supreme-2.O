// polymorphism

#include <iostream>
using namespace std;

// function overloading
// int add(int a, int b){
//     return a+b;
// }

// double add(double a, double b){
//     return a + b;
// }

// int add (int a, int b, int c){
//     return a + b + c;
// }


class Vector
{
    int x, y;

public:
    // Vector(int x, int y){
    //     this->x = x;
    //     this->y = y;
    // }

    // init list
    Vector(int x, int y) : x(x), y(y) {}

    void display()
    {
        cout << "x: " << x << " "
             << "y: " << y << endl;
    }

    // operator overloading
    void operator+(const Vector &src)
    {
        // this would point to v1
        // src would be ref to v2
        this->x = this->x + src.x;
        this->y = this->y + src.y;
    }

    void operator++(){
        this->x++;
        this->y++;
    }
};

int main()
{
    // cout<<add(1, 5)<<endl;
    // cout<<add(10.4, 2.4)<<endl;
    // cout<<add(1, 3, 6)<<endl;

    Vector v1(2, 3);
    Vector v2(5, 6);

    // v1 + v2;

    ++v1;
    // addition answer should be stored in v1
    v1.display();

    return 0;
}