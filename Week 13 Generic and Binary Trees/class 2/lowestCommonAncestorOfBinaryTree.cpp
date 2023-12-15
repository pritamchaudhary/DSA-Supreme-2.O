// leetcode 236. Lowest Common Ancestor of a Binary Tree

// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // base case
        if (root == NULL)
            return NULL;
        if (root->val == p->val)
            return p;
        if (root->val == q->val)
            return q;

        TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);

        if (leftAns == NULL && rightAns == NULL)
            return NULL;
        else if (leftAns != NULL && rightAns == NULL)
            return leftAns;
        else if (leftAns == NULL && rightAns != NULL)
            return rightAns;
        else
            return root;
    }
};