// find length of string

#include<iostream>
#include<string.h>
using namespace std;

int findLength(char ch[], int size){
    int length = 0;
    for(int i=0; i<size; i++){
        if(ch[i] == '\0'){
            // stop
            break;
        }
        else{
            length++;
        }
    }
    return length;
}

int findLengthUsingWhileLoop(char ch[], int size){
    int index = 0;
    while(ch[index] != '\0'){
        index++;
    }
    return index;
}

int main(){
    char ch[100];
    // cin>>ch;
    cin.getline(ch, 100);
    int len = findLength(ch, 100);
    int length = findLengthUsingWhileLoop(ch, 100);

    cout<<"length of string is: "<<len<<endl;
    cout<< "printing length: "<<length<<endl;


    // inbuilt function to print length of string 
    cout<<"length of string: "<<strlen(ch)<<endl;
    
    return 0;
}