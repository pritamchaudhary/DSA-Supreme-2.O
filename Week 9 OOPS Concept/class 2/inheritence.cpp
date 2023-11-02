#include<iostream>
using namespace std;

class Bird{
    public:
    int age;
    string color;
    int nol;
    int weight;

    void eat(){
        cout<<"Bird is eating"<<endl;
    }
    void fly(){
        cout<<"Bird is flying"<<endl;
    }
};

class Sparrow : public Bird {
    public:
    Sparrow(int age, string color, int nol, int weight){
        this->age = age;
        this->color = color;
        this->nol = nol;
        this->weight = weight;
    }

    void grassing(){
        cout<<"sparrow is grassing"<<endl;
    }
};

class Pegion : public Bird {
    public:
    void guttering(){
        cout<<"Pegion is guttering"<<endl;
    }
};  

int main(){
    Sparrow s(1, "Brown", 4, 10);
    cout<<s.color<<endl;
    s.eat();
    s.fly();

    Pegion p;
    p.eat();
    p.guttering();
    
    return 0;
}