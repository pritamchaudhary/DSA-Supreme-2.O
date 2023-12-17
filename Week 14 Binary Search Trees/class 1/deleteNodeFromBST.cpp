// delete a node from BST

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

Node* deleteFromBST(Node* root, int target){
    // base case
    if(root == NULL) return NULL;
    // 1 case solve
    if(root->data == target){
        // 4 cases
        // 1st case-> leaf node
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // 2nd case -> left non-null and right null
        else if(root->left != NULL && root->right == NULL){
            Node* childSubtree = root->left;
            delete root;
            return childSubtree;
        }
        // 3rd case -> left null and right non-null
        else if(root->left == NULL && root->right != NULL){
            Node* childSubtree = root->right;
            delete root;
            return childSubtree;
        }
        // 4th case -> left non-null and right non-null
        else{
            // (a) max value of left subtree
            Node* maxi = maxValue(root->left);
            // replace value from which we want to delete
            root->data = maxi->data;
            // delete actual maxi wali node
            root->left = deleteFromBST(root->left, maxi->data);
            return root;
        }
    }
    else if(root->data > target){
        // go to left 
        root->left = deleteFromBST(root->left, target);
    }
    else{
        // go to right
        root->right = deleteFromBST(root->right, target);
    }
    return root;
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

    int target;
    cout<<"Enter the target: "<<endl;
    cin>>target;

    while(target != -1){
        root = deleteFromBST(root, target);
        cout<<endl<<"printing the level order traversal: "<<endl;
        levelOrderTraversal(root);
        cout<<"Enter the target: "<<endl;
        cin>>target;
    }
    
    return 0;
}