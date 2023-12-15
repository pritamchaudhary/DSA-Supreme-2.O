// leetcode 112. Path Sum

// Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

// A leaf is a node with no children.

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
    bool solve(TreeNode *root, int targetSum, int sum)
    {
        // base case
        if (root == NULL)
        {
            return false;
        }
        sum += root->val;
        if (root->left == NULL && root->right == NULL)
        {
            if (sum == targetSum)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool leftAns = solve(root->left, targetSum, sum);
        bool rightAns = solve(root->right, targetSum, sum);
        return leftAns || rightAns;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        int sum = 0;
        bool ans = solve(root, targetSum, sum);
        return ans;
    }
};