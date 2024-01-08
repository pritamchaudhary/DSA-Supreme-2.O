// Inorder Predecessor in BST

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
    Node * inOrderPredecessor(Node *root, Node *x)
    {
        Node* pred = 0;
        Node* curr = root;
        while(curr){
            if(curr->data < x->data){
                pred = curr;
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        return pred;
    }
};