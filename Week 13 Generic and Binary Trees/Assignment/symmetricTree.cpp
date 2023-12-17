// leetcode 101. Symmetric Tree

// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

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
    bool isMirror(TreeNode *p, TreeNode *q)
    {
        // base case
        if (!p && !q)
        {
            return true;
        }
        if (p && q)
        {
            return (p->val == q->val) && isMirror(p->left, q->right) && isMirror(p->right, q->left);
        }
        return false;
    }

    bool isSymmetric(TreeNode *root)
    {
        return isMirror(root->left, root->right);
    }
};