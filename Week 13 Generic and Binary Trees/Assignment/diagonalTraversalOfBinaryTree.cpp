// GFG :- Diagonal Traversal of Binary Tree

// Given a Binary Tree, print the diagonal traversal of the binary tree.

// Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.
// If the diagonal element are present in two different subtress then left subtree diagonal element should be taken first and then right subtree. 

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// A binary tree node
struct Node
{
    int data;
    Node* left, * right;
};


vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if(root == NULL) return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        while(temp != NULL){
            ans.push_back(temp->data);
            if(temp->left != NULL){
                q.push(temp->left);
            }
            temp = temp->right;
        }
    }
    return ans;
}