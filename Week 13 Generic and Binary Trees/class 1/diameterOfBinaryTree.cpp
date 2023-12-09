// leetcode 543. Diameter of Binary Tree

// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them..

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
    int maxDepth(TreeNode *root)
    {
        // base case
        if (root == NULL)
        {
            return 0;
        }
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        int height = max(leftHeight, rightHeight) + 1;
        return height;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        // base case
        if (root == NULL)
        {
            return 0;
        }
        int option1 = diameterOfBinaryTree(root->left);
        int option2 = diameterOfBinaryTree(root->right);
        int option3 = maxDepth(root->left) + maxDepth(root->right);
        int diameter = max(option1, max(option2, option3));
        return diameter;
    }
};