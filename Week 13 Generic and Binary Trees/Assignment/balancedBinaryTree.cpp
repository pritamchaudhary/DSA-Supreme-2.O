// leetcode 110. Balanced Binary Tree

// Given a binary tree, determine if it is height-balanced.

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isbalanced = true;
    int height(TreeNode* root){
        if(!root) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        // check for current node, is it balanced?
        if(isbalanced && abs(lh - rh) > 1){
            isbalanced = false;
        }
        return max(lh, rh) + 1;
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return isbalanced;
    }
};