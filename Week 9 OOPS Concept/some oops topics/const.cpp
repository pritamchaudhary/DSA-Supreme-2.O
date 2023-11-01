// const keyword

#include<iostream>
using namespace std;

class abc{
    mutable int x;  //good practice is not to use mutable keyword, we can use this for debug purpose only
    int *y;
    const int z;

    public:
        // abc(){
        //     x = 0;
        //     y = new int(0);
        // }

        // constructor -> old style
        // abc(int _x, int _y, int _z = 0){
        //     x = _x;
        //     y = new int(_y);
        //     z = _z;
        // }

        // new style to use constructor -> initialization list
        abc(int _x, int _y, int _z=0):x(_x), y(new int(_y)), z(_z){
            cout<<"in init list"<<endl;
            *y = *y * 10;
        }

        int getX() const{
            x = 10;
            return x;
        }
        void setX(int _val){
            x = _val;
        }

        int getY() const
        {
            return *y;
        }
        void setY(int _val){
            *y = _val;
        }

        int getZ() const
        {
            return z;
        }
};

void printABC(const abc &a){
    cout<<a.getX()<<" "<<a.getY()<<" "<<a.getZ()<<endl;
}

int main(){
    const int x = 10;
    cout<<x<<endl;
    // initialization can be done but we can't reassign a value
    // x = 11; 

    // const with pointer
    const int *a = new int(2); 
    cout<<*a<<endl;  //const data but non-const pointer
    //int const *a = new int(2); //same as line no. 13
    // can't change the content of the pointer
    // *a = 20;

    int b = 20;
    a = &b; //pointer itself can be reassigned
    cout<<*a<<endl;

    // const pointer but non-const data
    int *const p = new int(2);
    cout<<*p<<endl;
    *p = 20;
    cout<<*p<<endl;

    // int q = 22;
    // p = &q;  //can't change, const pointer

    // const pointer, const data
    const int *const r = new int(10);
    cout<<*r<<endl;
    // *r = 50; //can't change
    // int s = 100;
    // r = &s; //can't change


    abc t(1,2,3);
    printABC(t);
    
    return 0;
}