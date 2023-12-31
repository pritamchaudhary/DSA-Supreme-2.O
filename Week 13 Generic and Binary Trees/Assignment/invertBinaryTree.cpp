// leetcode 226. Invert Binary Tree

// Given the root of a binary tree, invert the tree, and return its root.

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
    void solve(TreeNode *root)
    {
        // base case
        if (root == NULL)
            return;
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        solve(root->left);
        solve(root->right);
    }

    TreeNode *invertTree(TreeNode *root)
    {
        solve(root);
        return root;
    }
};