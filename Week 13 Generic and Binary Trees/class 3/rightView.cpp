// print right view

#include <iostream>
#include <queue>
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

void printRightView(Node* root, int level, vector<int> &rightView){
    // base case
    if(root == NULL){
        return;
    }
    if(level == rightView.size()){
        rightView.push_back(root->data);
    }
    printRightView(root->right, level+1, rightView);
    printRightView(root->left, level+1, rightView);
}

int main()
{
    Node *root = createTree();
    levelOrderTraversal(root);

    vector<int> rightView;
    printRightView(root, 0, rightView);

    cout<<"Printing right view: "<<endl;
    for(int i=0; i<rightView.size(); i++){
        cout<<rightView[i]<<" ";
    }

    // 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1

    return 0;
}