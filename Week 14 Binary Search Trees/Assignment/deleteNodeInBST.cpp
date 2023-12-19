// leetCode 450. Delete Node in a BST

// Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

// Basically, the deletion can be divided into two stages:

// Search for a node to remove.
// If the node is found, delete the node.

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
    TreeNode *maxValue(TreeNode *root)
    {
        // base case
        if (root == NULL)
            return NULL;
        TreeNode *temp = root;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        return temp;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // base case
        if (root == NULL)
            return NULL;
        // 1 case solve
        if (root->val == key)
        {
            // 4 case
            // 1st case: leaf node
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            // 2nd case: left non-null and right null
            else if (root->left != NULL && root->right == NULL)
            {
                TreeNode *childSubtree = root->left;
                delete root;
                return childSubtree;
            }
            // 3rd case: left null and right non-null
            else if (root->left == NULL && root->right != NULL)
            {
                TreeNode *childSubtree = root->right;
                delete root;
                return childSubtree;
            }
            else
            {
                // 4th case: left non-null and right non-null
                // (a) max value from left subtree
                TreeNode *maxi = maxValue(root->left);
                // (b) replacement
                root->val = maxi->val;
                // (c) delete actual maxi node
                root->left = deleteNode(root->left, maxi->val);
                return root;
            }
        }
        else if (root->val > key)
        {
            // left
            root->left = deleteNode(root->left, key);
        }
        else
        {
            // right
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};