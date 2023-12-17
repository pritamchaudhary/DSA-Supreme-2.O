// find min value in BST

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

Node* minValue(Node* root){
    if(root == NULL){
        cout<<"No minimum value"<<endl;
        return NULL;
    }
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

int main(){
    Node* root = NULL;
    createBST(root);
    levelOrderTraversal(root);

    Node* minNode = minValue(root);
    if(minNode == NULL){
        cout<<"There is no node in tree, so no min value"<<endl;
    }
    else{
        cout<<"Min value: "<<minNode->data<<endl;
    }
    
    return 0;
}