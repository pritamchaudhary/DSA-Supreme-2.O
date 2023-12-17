// search in BST

#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int data){
    // base case
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    // it's not the first one
    if(data > root->data){
        root->right = insertIntoBST(root->right, data);
    }
    else{
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void createBST(Node* &root){
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cout<<"Enter data: "<<endl;
        cin>>data;
    }
}

bool searchInBST(Node* root, int target){
    // base case
    if(root == NULL) return false;

    // 1 case solve
    if(root->data == target){
        return true;
    }
    // recursion call->left or right
    bool rightAns = false;
    bool leftAns = false;
    if(target > root->data){
        rightAns = searchInBST(root->right, target);
    }
    else{
        leftAns = searchInBST(root->left, target);
    }
    return rightAns || leftAns;
}

int main(){
    Node* root = NULL;
    createBST(root);

    int t;
    cout<<"Enter the target: "<<endl;
    cin>>t;

    while(t != -1){
        bool ans = searchInBST(root, t);
        if(ans == true){
            cout<<"Found"<<endl;
        }
        else{
            cout<<"Not Found"<<endl;
        }
        cout<<"Enter the target: "<<endl;
        cin>>t;
    }
    
    return 0;
}