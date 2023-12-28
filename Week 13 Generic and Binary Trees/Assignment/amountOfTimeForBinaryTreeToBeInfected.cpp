// leetcode 2385. Amount of Time for Binary Tree to Be Infected

// You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

// Each minute, a node becomes infected if:

// The node is currently uninfected.
// The node is adjacent to an infected node.
// Return the number of minutes needed for the entire tree to be infected.

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *makeNodeToParentMappingAndFindTargetNode(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parentMap, int start)
    {
        queue<TreeNode *> q;
        TreeNode *targetNode = 0;
        q.push(root);
        parentMap[root] = 0;
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            if (front->val == start)
            {
                targetNode = front;
            }
            if (front->left)
            {
                q.push(front->left);
                parentMap[front->left] = front;
            }
            if (front->right)
            {
                q.push(front->right);
                parentMap[front->right] = front;
            }
        }
        return targetNode;
    }

    int burnTheTree(TreeNode *targetNode, unordered_map<TreeNode *, TreeNode *> &parentMap)
    {
        unordered_map<TreeNode *, bool> isBurnt;
        queue<TreeNode *> q;
        int T = 0;
        q.push(targetNode);
        isBurnt[targetNode] = 1;
        while (!q.empty())
        {
            int size = q.size();
            bool isFireSpreaded = 0;
            for (int i = 0; i < size; i++)
            {
                TreeNode *front = q.front();
                q.pop();
                if (front->left && !isBurnt[front->left])
                {
                    q.push(front->left);
                    isBurnt[front->left] = 1;
                    isFireSpreaded = 1;
                }
                if (front->right && !isBurnt[front->right])
                {
                    q.push(front->right);
                    isBurnt[front->right] = 1;
                    isFireSpreaded = 1;
                }
                if (parentMap[front] && !isBurnt[parentMap[front]])
                {
                    q.push(parentMap[front]);
                    isBurnt[parentMap[front]] = 1;
                    isFireSpreaded = 1;
                }
            }
            if (isFireSpreaded)
                T++;
        }
        return T;
    }

    int amountOfTime(TreeNode *root, int start)
    {
        unordered_map<TreeNode *, TreeNode *> parentMap;
        TreeNode *targetNode = makeNodeToParentMappingAndFindTargetNode(root, parentMap, start);
        return burnTheTree(targetNode, parentMap);
    }
};
