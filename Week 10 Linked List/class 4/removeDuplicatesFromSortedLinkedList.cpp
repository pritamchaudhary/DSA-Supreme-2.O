// leetcode 83. Remove Duplicates from Sorted List

// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return head;
        }
        if(head->next == NULL){
            return head;
        }
        ListNode* temp = head;
        while(temp != NULL){
            if(temp->next != NULL && temp->val == temp->next->val){
                // remove
                ListNode* nextNode = temp->next;
                temp->next = nextNode->next;
                nextNode->next = NULL;
                delete nextNode;
            }
            else{
                temp = temp->next;
            }
        }
        return head;
    }
};