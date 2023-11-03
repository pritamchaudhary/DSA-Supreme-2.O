#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void sound()
    {
        cout << "Animal making sound" << endl;
    }

    virtual ~Animal()
    {
        cout << "Animal Dtor" << endl;
    }
};

class Dog : public Animal
{
public:
    void sound() override
    {
        cout << "Dog barking" << endl;
    }

    ~Dog()
    {
        cout << "Dog dtor" << endl;
    }
};

class Cat : public Animal
{
public:
    void sound() override
    {
        cout << "Cat Meowing" << endl;
    }

    ~Cat()
    {
        cout << "Cat dtor" << endl;
    }
};

class Parrot : public Animal
{
public:
    void sound() override
    {
        cout << "Parrot mitthu mitthu" << endl;
    }

    ~Parrot()
    {
        cout << "Parrot dtor" << endl;
    }
};

void sound(Animal *animal)
{
    animal->sound(); // polymorphic
    // animal->sound is behaving as per required object allocated at runtime
}

int main()
{
    // Dog *dog = new Dog();
    // dog->sound();

    Animal *animal = new Dog();
    // animal->sound();
    sound(animal);

    // animal = new Cat();
    // sound(animal);

    // animal = new Parrot();
    // sound(animal);

    delete animal;

    return 0;
}