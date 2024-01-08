// GFG :-> Brothers From Different Roots

// Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x, your task is to complete the function countPairs(), that returns the count of all pairs of (a, b), where a belongs to one BST and b belongs to another BST, such that a + b = x.

#include<iostream>
#include<stack>
using namespace std;

// Structure of the Node of the BST is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution
{
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        int ans = 0;
        stack<Node*> s1, s2;
        Node* a = root1;
        Node* b = root2;
        while(1){
            while(a){
                s1.push(a);
                a = a->left;
            }
            while(b){
                s2.push(b);
                b = b->right;
            }
            if(s1.empty() || s2.empty()){
                break;
            }
            auto atop = s1.top();
            auto btop = s2.top();
            int sum = atop->data + btop->data;
            if(sum == x){
                ans++;
                s1.pop();
                s2.pop();
                a = atop->right;
                b = btop->left;
            }
            else if(sum < x){
                s1.pop();
                a = atop->right;
            }
            else{
                s2.pop();
                b = btop->left;
            }
        }
        return ans;
    }
};