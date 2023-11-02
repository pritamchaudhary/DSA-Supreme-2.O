
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
        int *v;

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
        this->v = new int(10);
        cout<<"Student Parameterized constructor without gf called"<<endl;
    }

    // copy constructor
    Student (const Student &srcobj){
        cout<<"Student copy constructor called"<<endl;
        this->name = srcobj.id;
        this->age = srcobj.age;
        this->present = srcobj.present;
        this->name = srcobj.name;
        this->nos = srcobj.nos;
        this->gf = srcobj.gf;
    }

    // getter or setter
    string getGfName(){
        return gf;
        // return this->gf;
    }

    void setGfName(string gf){
        this->gf = gf;
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

    ~Student(){
        cout<<"Student destructor called"<<endl;
        delete v;
    }

    private:
        void chat(){
            cout<<"Chatting"<<endl;
        }
};

int main(){
    // Student s1(1, 21, 1, "Pritam", 5, "prit");
    // // Student s2 = s1;
    // Student s2(s1);
    // cout<<s1.name<<endl;
    // cout<<s2.name<<endl;

    // {
    //     Student s1(1, 21, 1, "Pritam", 5, "prit");
    //     cout<<s1.name<<endl;
    // }
    // Student s2;

    Student s1(1, 21, 1, "Pritam", 5, "prit");
    cout<<s1.name<<endl;
    cout<<s1.getGfName()<<endl;
    s1.setGfName("Prity");
    cout<<s1.getGfName()<<endl;

    
    return 0;
}