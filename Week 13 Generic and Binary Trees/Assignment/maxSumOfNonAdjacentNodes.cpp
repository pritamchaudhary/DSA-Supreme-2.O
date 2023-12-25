// GFG :- Maximum sum of Non-adjacent nodes

// Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.

#include<iostream>
using namespace std;

//Node Structure

struct Node
{
    int data;
    Node* left;
    Node* right;
};


class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int, int> getMaxSum_helper(Node* root){
        if(!root) return {0, 0};
        
        auto left = getMaxSum_helper(root->left);
        auto right = getMaxSum_helper(root->right);
        
        // sum including the node
        int a = root->data + left.second + right.second;
        // sum excluding the node
        int b = max(left.first, left.second) + max(right.first, right.second);
        
        return {a, b};
    }
    
    int getMaxSum(Node *root) 
    {
        auto ans = getMaxSum_helper(root);
        return max(ans.first, ans.second);
    }
};