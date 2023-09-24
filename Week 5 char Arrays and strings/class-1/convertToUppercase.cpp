// convert to uppercase

#include<iostream>
using namespace std;

void convertToUppercase(char ch[], int n){
    int index = 0;
    while(ch[index] != '\0'){
        char currCharacter = ch[index];
        // check if lowercase, then convert to uppercase
        if(currCharacter >= 'a' && currCharacter <= 'z'){
            ch[index] = currCharacter - 'a' + 'A';
        }

        // if(ch[index] >= 'a' && ch[index] <= 'z'){
        //     ch[index] = ch[index] - 'a' + 'A';
        // }

        index++;
    }
}

int main(){
    char ch[100];
    cin.getline(ch, 100);

    cout<<"Before "<<ch<<endl;

    convertToUppercase(ch, 100);

    cout<<"After "<<ch <<endl;
    
    return 0;
}