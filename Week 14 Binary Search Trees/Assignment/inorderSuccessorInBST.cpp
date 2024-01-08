// GFG :-> Inorder Successor in BST

// Given a BST, and a reference to a Node x in the BST. Find the Inorder Successor of the given node in the BST.

#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node* succ = 0;
        Node* curr = root;
        while(curr){
            if(curr->data > x->data){
                succ = curr;
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }
        return succ;
    }
};