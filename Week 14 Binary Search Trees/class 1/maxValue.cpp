// // find max value in BST

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

Node* maxValue(Node* root){
    if(root == NULL){
        return NULL;
    }
    // if tree has node > 0 count
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

int main(){
    Node* root = NULL;
    createBST(root);
    levelOrderTraversal(root);

    Node* maxNode = maxValue(root);
    if(maxNode == NULL){
        cout<<"There is no node in tree, so no max value"<<endl;
    }
    else{
        cout<<"Max value: "<<maxNode->data<<endl;
    }
    
    return 0;
}