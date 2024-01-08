// leetcode 1382. Balance a Binary Search Tree

// Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

// A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

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
    void inorder(TreeNode *root, vector<int> &in)
    {
        // base case
        if (!root)
            return;
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }

    TreeNode *buildTree(vector<int> &in, int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(in[mid]);
        root->left = buildTree(in, start, mid - 1);
        root->right = buildTree(in, mid + 1, end);
        return root;
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> in;
        inorder(root, in);
        // build balance BST using inorder traversal
        return buildTree(in, 0, in.size() - 1);
    }
};