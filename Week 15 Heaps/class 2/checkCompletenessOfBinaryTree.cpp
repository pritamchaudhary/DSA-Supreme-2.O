// leetcode 958. Check Completeness of a Binary Tree

// Given the root of a binary tree, determine if it is a complete binary tree.

// In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

#include <iostream>
#include<queue>
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
    bool levelOrderTraversal(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        bool nullFound = false;
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            if (front == NULL)
            {
                nullFound = true;
            }
            else
            {
                if (nullFound)
                {
                    return false;
                }
                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }

    bool isCompleteTree(TreeNode *root)
    {
        return levelOrderTraversal(root);
    }
};
