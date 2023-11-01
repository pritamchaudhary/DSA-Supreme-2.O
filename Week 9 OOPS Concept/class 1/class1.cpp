
#include<iostream>
using namespace std;

class Student{

    private:
        string gf;
    
    public:
        int id;
        int age;
        bool present;
        string name;
        int nos;

    // default constructor -> assigns garbage value
    Student(){
        cout<<"Student constructor called"<<endl;
    }

    // parameterized constructor
    Student(int _id, int _age, bool _present, string _name, int _nos, string _gfname){
        id = _id;
        age = _age;
        present = _present;
        name = _name;
        nos = _nos;
        gf = _gfname;
        cout<<"Student Parameterized constructor called"<<endl;
    }

    Student(int id, int age, bool present, string name, int nos){
        this->id = id;
        this->age = age;
        this->present = present;
        this->name = name;
        this->nos = nos;
        cout<<"Student Parameterized constructor without gf called"<<endl;
    }

    void study(){
        cout<< "studying "<<endl;
    }
    void sleep(){
        cout<<"Sleeping"<<endl;
    }
    void bunk(){
        cout<<"Bunking"<<endl;
    }
    private:
        void chat(){
            cout<<"Chatting"<<endl;
        }
};

int main(){
    cout<<sizeof(Student)<<endl;

    Student s1;
    
    Student s2(1, 21, 1, "Pritam", 5, "Kartikay");
    cout<<s2.name<<endl;
    cout<<s2.age<<endl;

    Student s3(2, 19, 0, "Nishant", 6);
    cout<<s3.name<<endl;
    cout<<s3.age<<endl;

    // allocating on heap
    Student *s4 = new Student(3, 18, 1, "Sushant", 6);
    cout<<s4->name<<endl;
    cout<<(*s4).name<<endl;

    delete s4; //no leak

    // s1.name = "Pritam";
    // s1.id = 1;
    // s1.age = 21;
    // s1.nos = 5;
    // s1.present = 0;

    // Student s2;
    // s2.name = "Nishant";
    // s2.id = 2;
    // s2.age = 19;
    // s2.nos = 5;
    // s2.present = 1;

    
    return 0;
}