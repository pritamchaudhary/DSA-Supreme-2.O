// implementation

#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* createTree(){
    cout<<"Enter the value for node: "<<endl;
    int data;
    cin>>data;
    if(data == -1){
        return NULL;
    }
    // step1: create node
    Node* root = new Node(data);
    // step2: create left subtree
    cout<<"Left of node: "<<root->data<<endl;
    root->left = createTree();
    // step3: create right subtree
    cout<<"Right of node: "<<root->data<<endl;
    root->right = createTree();
    return root;
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
    // traversal
    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            // valid node wala case
            cout<<front->data<<" ";

            if(front->left != NULL){
                q.push(front->left);
            }
            if(front->right != NULL){
                q.push(front->right);
            }
        }       
    }
}

int main(){
    Node* root = createTree();
    // cout<<root->data<<endl;

    cout<<"printing preOrder: ";
    preOrderTraversal(root);
    cout<<endl;

    cout<<"printing inOrder: ";
    inOrderTraversal(root);
    cout<<endl;

    cout<<"printing postOrder: ";
    postOrderTraversal(root);
    cout<<endl;

    cout<<"Level order: ";
    levelOrderTraversal(root);
    cout<<endl;

    return 0;
}