// print left view

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

void printLeftView(Node *root, int level, vector<int> &leftView)
{
    // base case
    if (root == NULL)
        return; 

    if (level == leftView.size())
    {
        // iska matlab leftview ki node mil gayi hai, store karlo
        leftView.push_back(root->data);
    }
    printLeftView(root->left, level + 1, leftView);
    printLeftView(root->right, level + 1, leftView);
}

int main()
{
    Node *root = createTree();
    levelOrderTraversal(root);

    vector<int> leftView;
    printLeftView(root, 0, leftView);

    cout<<"Printing left view: "<<endl;
    for(int i=0; i<leftView.size(); i++){
        cout<<leftView[i]<<" ";
    }

    // 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1

    return 0;
}