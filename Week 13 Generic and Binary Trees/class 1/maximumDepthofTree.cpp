// leetcode 104. Maximum Depth of Binary Tree

// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

#include<iostream>
#include<queue>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int count = 1;
        // traversal
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front == NULL){
                cout<<endl;
                if(!q.empty()){
                    count++;
                    q.push(NULL);
                }
            }
            else{
                // valid node wala case
                // cout<<front->data<<" ";

                if(front->left != NULL){
                    q.push(front->left);
                }
                if(front->right != NULL){
                    q.push(front->right);
                }
            }       
        }
        return count;
    }
};