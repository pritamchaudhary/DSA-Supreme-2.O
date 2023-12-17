// create binary search trees

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

// pre-order traversal
void preOrderTraversal(Node* root){
    // base case
    if(root == NULL){
        return;
    }
    // NLR
    // N
    cout<<root->data<<" ";
    // L
    preOrderTraversal(root->left);
    // R
    preOrderTraversal(root->right);
}

// in-order traversal
void inOrderTraversal(Node* root){
    // base case
    if(root == NULL){
        return;
    }
    // LNR
    // L
    inOrderTraversal(root->left);
    // N
    cout<<root->data<<" ";
    // R
    inOrderTraversal(root->right);
}

// post-order traversal
void postOrderTraversal(Node* root){
    // base case
    if(root == NULL){
        return;
    }
    // LRN
    // L
    postOrderTraversal(root->left);
    // R
    postOrderTraversal(root->right);
    // N
    cout<<root->data<<" ";
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
}

int main(){
    Node* root = NULL;
    createBST(root);
    levelOrderTraversal(root);

    cout<<"printing preOrder: ";
    preOrderTraversal(root);
    cout<<endl;

    cout<<"printing inOrder: ";
    inOrderTraversal(root);
    cout<<endl;

    cout<<"printing postOrder: ";
    postOrderTraversal(root);
    cout<<endl;
    
    return 0;
}