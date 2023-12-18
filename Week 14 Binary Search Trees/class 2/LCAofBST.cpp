// leetCode 235. Lowest Common Ancestor of a Binary Search Tree

// Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

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
        {
            return NULL;
        }
        // case 1 : p and q both comes in left subtree of root node
        if (p->val < root->val && q->val < root->val)
        {
            TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);
            return leftAns;
        }
        // case 2 : p and q both comes in right subtree of root node
        if (p->val > root->val && q->val > root->val)
        {
            TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);
            return rightAns;
        }
        // case 3 : p is in left subtree of root node and q is in right subtree of root node
        if (p->val < root->val && q->val > root->val)
        {
            return root;
        }
        // case 4 : p is in right subtree of root node and q is in left subtree of root node
        if (p->val > root->val && q->val < root->val)
        {
            return root;
        }
        return root;
    }
};