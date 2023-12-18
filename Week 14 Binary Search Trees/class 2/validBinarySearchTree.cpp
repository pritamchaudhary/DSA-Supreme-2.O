// leetCode 98. Validate Binary Search Tree

// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

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
    bool solve(TreeNode *root, long long int lowerBound, long long int upperBound)
    {
        // base case
        if (root == NULL)
        {
            return true;
        }
        int cond1 = (root->val > lowerBound);
        int cond2 = (root->val < upperBound);
        int leftAns = solve(root->left, lowerBound, root->val);
        int rightAns = solve(root->right, root->val, upperBound);

        if (cond1 && cond2 && leftAns && rightAns)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isValidBST(TreeNode *root)
    {
        long long int lowerBound = -21474836457;
        long long int upperBound = 21474836457;
        bool ans = solve(root, lowerBound, upperBound);
        return ans;
    }
};