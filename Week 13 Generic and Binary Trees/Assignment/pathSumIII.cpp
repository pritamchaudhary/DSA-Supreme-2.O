// leetcode 437. Path Sum III

// Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

// The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

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
    int ans = 0;
    void pathFromOneRoot(TreeNode *root, long long sum)
    {
        if (!root)
            return;
        if (sum == root->val)
        {
            ans++;
        }
        pathFromOneRoot(root->left, sum - root->val);
        pathFromOneRoot(root->right, sum - root->val);
    }

    int pathSum(TreeNode *root, long long targetSum)
    {
        if (root)
        {
            pathFromOneRoot(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return ans;
    }
};