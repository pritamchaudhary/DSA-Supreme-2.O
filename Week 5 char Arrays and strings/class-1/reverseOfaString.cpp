// reverse of a string

#include<iostream>
using namespace std;

void reverseOfString(char ch[], int size){
    int i = 0;
    int j = size-1;
    while(i <= j){
        swap(ch[i], ch[j]);
        i++;
        j--;
    }
}

int findLength(char ch[], int size){
    int index = 0;
    while(ch[index] != '\0'){
        index++;
    }
    return index;
}

int main(){
    char ch[100];
    cin.getline(ch, 100);

    cout<<"Before "<<ch<<endl;
    int length = findLength(ch, 100);
    reverseOfString(ch, length);
    cout<<"After "<<ch<<endl;
    
    return 0;
}