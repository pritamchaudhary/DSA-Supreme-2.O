// GFG :- Median of BST

// Given a Binary Search Tree of size N, find the Median of its Node values.

#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int findNodeCount(Node *root)
{
    int count = 0;
    Node *curr = root;
    while (curr)
    {
        // left node is null, then, visit it and go right
        if (curr->left == nullptr)
        {
            count++;
            curr = curr->right;
        }
        // left node is not null
        else
        {
            // find inorder predecessor
            Node *pred = curr->left;
            while (pred->right != curr && pred->right)
            {
                pred = pred->right;
            }
            // if pred right node is null, then, go left after establishing link from pred to curr
            if (pred->right == nullptr)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                // left is already visited, go right after visiting curr node while removing the link
                pred->right = nullptr;
                count++;
                curr = curr->right;
            }
        }
    }
    return count;
}

float findActualMedian(Node *root, int n)
{
    int i = 0;
    int odd1 = (n+1)/2, odd1Val = -1;
    int even1 = n/2, even1Val = -1;
    int even2 = (n/2) + 1, even2Val = -1;
    Node *curr = root;
    while (curr)
    {
        // left node is null, then, visit it and go right
        if (curr->left == nullptr)
        {
            i++;
            if(i == odd1) odd1Val = curr->data;
            if(i == even1) even1Val = curr->data;
            if(i == even2) even2Val = curr->data;
            curr = curr->right;
        }
        // left node is not null
        else
        {
            // find inorder predecessor
            Node *pred = curr->left;
            while (pred->right != curr && pred->right)
            {
                pred = pred->right;
            }
            // if pred right node is null, then, go left after establishing link from pred to curr
            if (pred->right == nullptr)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                // left is already visited, go right after visiting curr node while removing the link
                pred->right = nullptr;
                i++;
                if(i == odd1) odd1Val = curr->data;
                if(i == even1) even1Val = curr->data;
                if(i == even2) even2Val = curr->data;
                curr = curr->right;
            }
        }
    }
    float median = 0;
    if((n & 1) == 0){
        // even 
        median = (even1Val + even2Val)/2.0;
    }
    else{
        // odd
        median = odd1Val;
    }
    return median;
}

float findMedian(struct Node *root)
{
    int n = findNodeCount(root);
    return findActualMedian(root, n);
}