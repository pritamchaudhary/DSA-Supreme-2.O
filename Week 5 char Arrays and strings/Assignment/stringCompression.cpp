// leetcode 

// Given an array of characters chars, compress it using the following algorithm:

// Begin with an empty string s. For each group of consecutive repeating characters in chars:

        // If the group's length is 1, append the character to s.
        // Otherwise, append the character followed by the group's length.
// The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

// After you are done modifying the input array, return the new length of the array.

// You must write an algorithm that uses only constant extra space.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        int count = 1;
        char prev = chars[0];
        for(int i=1; i<chars.size(); i++){
            if(chars[i] == prev){
                count++;
            }
            else{
                chars[index++] = prev;
                if(count > 1){
                    int start = index;
                    while(count){
                        chars[index++] = (count % 10) + '0';
                        count /= 10;
                    }
                    reverse(chars.begin()+start, chars.begin()+ index);
                }
                prev = chars[i];
                count = 1;
            }
        }
        chars[index++] = prev;
        if(count > 1){
            int start = index;
            while(count){
                chars[index++] = (count % 10) + '0';
                count /= 10;
            }
            reverse(chars.begin()+start, chars.begin()+index);
        }
        return index; 
    }
};