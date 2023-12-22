// input:-> CBT + BST -> convert into valid max heap

#include<iostream>
#include<vector>
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

void storeInOrderTraversal(Node* root, vector<int>& in){
    // base case
    if(root == NULL) return;
    // LNR
    storeInOrderTraversal(root->left, in);
    in.push_back(root->data);
    storeInOrderTraversal(root->right, in);
}

void replaceUsingPostOrder(Node* root, vector<int> in, int &index){
    // base case
    if(root == NULL) return;
    // LRN
    replaceUsingPostOrder(root->left, in, index);
    replaceUsingPostOrder(root->right, in, index);
    root->data = in[index];
    index++;
}

Node* convertBSTintoMaxHeap(Node* root){
    // store inOrder
    vector<int> inOrder;
    storeInOrderTraversal(root, inOrder);

    // ṛeplace the node values with the sorted inOrder values using postOrder traversal
    int index = 0;
    replaceUsingPostOrder(root, inOrder, index);
    return root;
}

int main(){
    Node* root = NULL;
    createBST(root);
    cout<<"printing the BST: "<<endl;

    levelOrderTraversal(root);
    cout<<endl;
    cout<<"converting into Heap: "<<endl;

    root = convertBSTintoMaxHeap(root);
    cout<<"printing the Heap: "<<endl;
    levelOrderTraversal(root);
    
    return 0;
}