// print bottom view

#include <iostream>
#include <queue>
#include<map>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree()
{
    cout << "Enter the value for node: ";
    int value;
    cin >> value;

    if (value == -1)
        return NULL;

    // create node
    Node *root = new Node(value);
    cout << "Enter left value: " << value << endl;
    root->left = createTree();
    cout << "Enter right value: " << value << endl;
    root->right = createTree();
    return root;
}

void preOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    cout<<endl;
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";
            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}

void printBottomView(Node* root){
    map<int, int> hdToNodeMap;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;
        // overwrite answers so that the deeper nodes can be stored
            hdToNodeMap[hd] = frontNode->data;

        // child ko dekhna hai
        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    cout<<"Printing Bottom view: "<<endl;
    for(auto i: hdToNodeMap){
        cout<<i.second<<" ";
    }
}

int main()
{
    Node *root = createTree();
    levelOrderTraversal(root);

    printBottomView(root);
    // 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1

    return 0;
}