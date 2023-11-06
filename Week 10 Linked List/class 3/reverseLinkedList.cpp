// leetcode 206. Reverse Linked List

// Given the head of a singly linked list, reverse the list, and return the reversed list.

#include<iostream>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseUsingRecursion(ListNode* prev, ListNode* curr){
        // base case
        if(curr == NULL) return prev;
        // 1 case solution
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;

        // recursive call
        ListNode* reverseAns = reverseUsingRecursion(prev, curr);
        return reverseAns;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        return reverseUsingRecursion(prev, curr);
    }
};