// // construct tree from preOrder and inorder traversal

#include <iostream>
#include<queue>
#include<map>
using namespace std;

class Node{
  public:
	int data;
	Node* left;
	Node* right;

	Node(int val) {
	  this->data = val;
	  this->left = NULL;
	  this->right = NULL;
	}
};

//it returns root node of the created tree
Node* createTree() {
  cout << "enter the value for Node: " << endl;
  int data;
  cin >> data;

  if(data == -1) {
	return NULL;
  }
  //Step1: create Node
  Node* root = new Node(data);
  //Step2: Create left subtree
  //cout << "left of Node: " << root->data << endl;
  root->left = createTree();
  //Step3: Craete right subtree
  //cout << "right of Node: " << root->data << endl;
  root->right = createTree();
  return root;

}

void preOrderTraversal(Node* root) {
	//base case
	if(root == NULL) {
		return;
	}
	// N L R
	//N 
	cout << root->data << " ";
	// L
	preOrderTraversal(root->left);
	// R
	preOrderTraversal(root->right);
}

void inorderTraversal(Node* root) {
	//LNR
	//base case
	if(root == NULL) {
		return;
	}
	//L
	inorderTraversal(root->left);
	// N
	cout << root->data << " ";
	// R
	inorderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
	//LRN
	//base case
	if(root == NULL) {
		return;
	}
	//L
	postOrderTraversal(root->left);
	//R
	postOrderTraversal(root->right);
	//N
	cout << root->data << " ";
}

void levelOrderTraversal(Node* root) {
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	//asli traversal start krete h 

	while(!q.empty()) {
		Node* front = q.front();
		q.pop();

		if(front == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			//valid node wala case
			cout << front->data << " ";

			if(front->left != NULL) {
				q.push(front->left);
			}
			if(front->right != NULL) {
				q.push(front->right);
			}
		}
	}
}

int searchInorder(int inorder[], int size, int target){
  for(int i=0; i<size; i++) {
    if(inorder[i] == target) {
      return i;
    }
  }
  return -1;
}

void createMapping(int inorder[], int size, map<int,int> &valueToIndexMap) {

    for(int i=0; i<size; i++) {
      int element = inorder[i];
      int index = i;
      valueToIndexMap[element] = index;
    }

}

Node* constructTreeFromPreAndInorderTraversal( map<int,int> &valueToIndexMap, int preOrder[], int inOrder[], int &preIndex, int inOrderStart, int inOrderEnd, int size) {
  //base case
  if(preIndex >= size || inOrderStart > inOrderEnd) {
    return NULL;
  }

  //1 case main solve krta hu
  int element = preOrder[preIndex];
  preIndex++;
  Node* root = new Node(element);
  //element search krna padega  inorder me 
  //int position = searchInorder(inOrder, size, element);
  int position = valueToIndexMap[element];
  //baaaki recursion sambhal lega
  root->left = constructTreeFromPreAndInorderTraversal(valueToIndexMap,preOrder, inOrder, preIndex, inOrderStart, position-1, size);

  root->right = constructTreeFromPreAndInorderTraversal(valueToIndexMap,preOrder, inOrder, preIndex, position+1, inOrderEnd, size);

  return root;

}

int main() {
  int inorder[] = {10,8,6,2,4,12};
  int preOrder[] = {2,8,10,6,4,12};
  int size = 6;
  int preOrderIndex = 0;
  int inorderStart = 0;
  int inorderEnd = 5;
  map<int,int> valueToIndexMap;
  createMapping(inorder, size, valueToIndexMap);

  Node* root = constructTreeFromPreAndInorderTraversal(valueToIndexMap,preOrder, inorder, preOrderIndex, inorderStart,inorderEnd, size);

  cout << "Printing the entire tree: " << endl;
  levelOrderTraversal(root);
  return 0;
}