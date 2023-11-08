// leetcode 25. Reverse Nodes in k-Group

// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

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
    int getLength(ListNode* head){
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // base case
        if(head == NULL){
            return head;
        }
        if(head->next == NULL){
            return head;
        }
        // 1 case solution
        ListNode* prev = NULL;
        ListNode* curr = head;
        int position = 0;
        ListNode* nextNode = curr->next;
        int len = getLength(head);
        if(len < k){
            return head;
        }
        while(position < k){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            position++;
        }
        ListNode* recursionAns = NULL;
        if(nextNode != NULL){
            ListNode* recursionAns = reverseKGroup(nextNode, k);
            head->next = recursionAns;
        }
        return prev;
    }
};