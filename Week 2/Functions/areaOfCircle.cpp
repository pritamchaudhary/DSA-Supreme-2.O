// function to find area of circle

#include<iostream>
#include<cmath>
using namespace std;

float areaOfCircle(float radius){
    // float ans = 3.14 * radius * radius;
    float ans = 3.14 * pow(radius, 2);
    return ans;
}

int main(){
    float radius;
    cin>>radius;
    float area = areaOfCircle(radius);
    cout<< "Area of circle is: "<< area <<endl;
    
    return 0;
}
