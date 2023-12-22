// CBT -> is valid max heap or not

#include<iostream>
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

// class Info{
//     public:
//     int maxVal;
//     bool isHeap;
    
//     Info(int a, int b){
//         this->maxVal = a;
//         this->isHeap = b;
//     }
// };

// Info checkMaxHeap(Node* root){
//     // base case
//     if(root == NULL){
//         Info temp;
//         temp.maxVal = INT_MIN;
//         temp.isHeap = true;
//         return temp;
//     }
//     if(root->left == NULL && root->right == NULL){
//         Info temp;
//         temp.maxVal = root->data;
//         temp.isHeap = true;
//         return temp;
//     }

//     Info leftAns = checkMaxHeap(root->left);
//     Info rightAns = checkMaxHeap(root->right);

//     // 1 case solve
//     if(root->data > leftAns.maxVal && root->data > rightAns.maxVal && rightAns.isHeap && leftAns.isHeap){
//         Info ans;
//         ans.maxVal = root->data;
//         ans.isHeap = true;
//         return ans;
//     }
//     else{
//         Info ans;
//         ans.maxVal = max(root->data, max(leftAns.maxVal, rightAns.maxVal));
//         ans.isHeap = false;
//         return ans;
//     }
// }


pair<bool, int> solve(Node* root) {
        //base case
        if(root == NULL) {
                pair<bool,int> p = make_pair(true, INT_MIN);
                return p;
        }
        if(root->left == NULL && root->right == NULL)
        {
                //leaf node
                pair<bool,int> p = make_pair(true, root->data);
                return p;
        }

        pair<bool, int> leftAns = solve(root->left);
        pair<bool, int> rightAns = solve(root->right);

        if(leftAns.first == true &&
          rightAns.first == true &&
          root->data > leftAns.second &&
          root->data > rightAns.second) {
                  pair<bool, int> p =  make_pair(true, root->data);
                  return p;
          }
         
          else {
                  pair<bool, int> p =  make_pair(false, root->data);
                  return p;
          }
}

int main(){
    return 0;
}