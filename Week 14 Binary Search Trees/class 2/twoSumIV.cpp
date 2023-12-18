// leetCode 653. Two Sum IV - Input is a BST

// Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

#include <iostream>
#include <vector>
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
    void storeInOrder(TreeNode *root, vector<int> &inOrder)
    {
        // base case
        if (root == NULL)
        {
            return;
        }
        // LNR
        // L
        storeInOrder(root->left, inOrder);
        // N
        inOrder.push_back(root->val);
        // R
        storeInOrder(root->right, inOrder);
    }

    bool findTarget(TreeNode *root, int k)
    {
        vector<int> inOrder;
        storeInOrder(root, inOrder);
        // find target using 2 pointer approach
        int start = 0;
        int end = inOrder.size() - 1;
        while (start < end)
        {
            int sum = inOrder[start] + inOrder[end];
            if (sum == k)
                return true;
            else if (sum > k)
                end--;
            else if (sum < k)
                start++;
        }
        return false;
    }
};