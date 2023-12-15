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

class Solution
{
public:
    int height(TreeNode *root)
    {
        // base case
        if (root == NULL)
        {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int finalAns = max(leftHeight, rightHeight) + 1;
        return finalAns;
    }

    bool isBalanced(TreeNode *root)
    {
        // base case
        if (root == NULL)
        {
            return true;
        }
        // current node-> solve
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diff = abs(leftHeight - rightHeight);

        bool currNodeAns = (diff <= 1);

        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);

        if (leftAns && rightAns && currNodeAns)
        {
            return true;
        }
        return false;
    }
};