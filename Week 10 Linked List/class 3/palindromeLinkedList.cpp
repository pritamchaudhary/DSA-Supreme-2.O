// leetcode 234. Palindrome Linked List

// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL){
            fast = fast->next;
            if(fast->next != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }

    ListNode* reverseUsingRecursion(ListNode* prev, ListNode* curr){
        // base case
        if(curr == NULL) return prev;
        // 1 case solution
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;

        // recursive call
        return reverseUsingRecursion(prev, curr);
    }

    bool compareList(ListNode* head1, ListNode* head2){
        while(head1 != NULL & head2 != NULL){
            if(head1 -> val != head2 -> val){
                return false;
            }
            else{
                head1 = head1->next;
                head2 = head2->next;
            }
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        // break into 2 halves
        ListNode* midNode = middleNode(head);
        ListNode* head2 = midNode->next;
        midNode->next = NULL;
        // reverse second half
        ListNode* prev = NULL;
        ListNode* curr = head2;
        head2 = reverseUsingRecursion(prev, curr);
        // compare both Linked List
        bool ans = compareList(head, head2);
        return ans;
    }
};