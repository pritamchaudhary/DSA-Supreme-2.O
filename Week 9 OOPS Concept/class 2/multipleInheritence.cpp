#include <iostream>
using namespace std;

class Person
{
public:
    void walk()
    {
        cout << "Walking..." << endl;
    }
};

class Teacher: virtual public Person
{
public:
    void teach()
    {
        cout << "Teaching..." << endl;
    }
};

class Researcher: virtual public Person
{
public:
    void research()
    {
        cout << "Researching..." << endl;
    }
};

// multiple inheritence

class Professor : public Teacher, public Researcher
{
public:
    void bore()
    {
        cout << "Boring..." << endl;
    }
};

int main()
{
    Professor p;
    
    // Diamond Problem
    // solution 1: Scope Resolution
    // p.Teacher::walk();
    // p.Researcher::walk();

    // solution 2 : using virtual
    p.walk();

    return 0;
}