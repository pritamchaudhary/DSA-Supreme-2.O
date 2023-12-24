// GFG :-> Transform to Sum Tree

// Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree. The values of leaf nodes are changed to 0.

#include<iostream>
using namespace std;

// A binary tree node
struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    
    int sum(Node* root){
        // base case
        if(!root) return 0;
        if(!root->left && !root->right){
            // leaf node
            int temp = root->data;
            root->data = 0;
            return temp;
        }
        int lSum = sum(root->left);
        int rSum = sum(root->right);
        int temp = root->data;
        root->data = lSum + rSum;
        return root->data + temp;
    }
    
    void toSumTree(Node *node)
    {
        sum(node);
    }
};