// construct tree from post order and inorder traversal

#include <iostream>
#include <queue>
#include <map>
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

// it returns root node of the created tree
Node *createTree()
{
    cout << "enter the value for Node: " << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    // Step1: create Node
    Node *root = new Node(data);
    // Step2: Create left subtree
    root->left = createTree();
    // Step3: Craete right subtree
    root->right = createTree();
    return root;
}

void preOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    // N L R
    // N
    cout << root->data << " ";
    // L
    preOrderTraversal(root->left);
    // R
    preOrderTraversal(root->right);
}

void inorderTraversal(Node *root)
{
    // LNR
    // base case
    if (root == NULL)
    {
        return;
    }
    // L
    inorderTraversal(root->left);
    // N
    cout << root->data << " ";
    // R
    inorderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    // LRN
    // base case
    if (root == NULL)
    {
        return;
    }
    // L
    postOrderTraversal(root->left);
    // R
    postOrderTraversal(root->right);
    // N
    cout << root->data << " ";
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    // asli traversal start krete h

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
            // valid node wala case
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

void createMapping(int inorder[], int size, map<int, int> &valueToIndexMap)
{

    for (int i = 0; i < size; i++)
    {
        int element = inorder[i];
        int index = i;
        valueToIndexMap[element] = index;
    }
}

Node *constructTreeFromPostAndInorderTraversal(map<int, int> &valueToIndexMap, int postorder[], int inorder[], int &postIndex, int inorderStart, int inorderEnd, int size)
{

    if (postIndex < 0 || inorderStart > inorderEnd)
    {
        return NULL;
    }

    // 1 case main solve krunga
    int element = postorder[postIndex];
    postIndex--;
    Node *root = new Node(element);
    // search karo inorder me
    int position = valueToIndexMap[element];
    // baaki recursion sambhal lega
    // right ki call pehle lagegi
    root->right = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postorder, inorder, postIndex, position + 1, inorderEnd, size);

    root->left = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postorder, inorder, postIndex, inorderStart, position - 1, size);

    return root;
}

int main()
{
    int inorder[] = {8, 14, 6, 2, 10, 4};
    int postorder[] = {8, 6, 14, 4, 10, 2};
    int size = 6;
    int postIndex = size - 1;
    int inorderStart = 0;
    int inorderEnd = size - 1;
    map<int, int> valueToIndexMap;
    createMapping(inorder, size, valueToIndexMap);
    Node *root = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postorder, inorder, postIndex, inorderStart, inorderEnd, size);
    cout << "Printing the entire tree: " << endl;
    levelOrderTraversal(root);
    return 0;
}