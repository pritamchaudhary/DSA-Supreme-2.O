// leetCode 230. Kth Smallest Element in a BST

// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

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
    int kthSmallest(TreeNode *root, int &k)
    {
        // base case
        if (root == NULL)
        {
            return -1;
        }
        // inOrder-> LNR
        // L
        int leftAns = kthSmallest(root->left, k);
        if (leftAns != -1)
        {
            return leftAns;
        }
        // N
        k--;
        if (k == 0)
        {
            return root->val;
        }
        // R
        int rightAns = kthSmallest(root->right, k);
        return rightAns;
    }
};