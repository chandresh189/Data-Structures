#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
	Node *left, *right;
	int data;
}*root=nullptr;

Node *NewNode(int data) {
	Node *ptr = new Node;
	ptr->data = data;
	ptr->left = nullptr;
	ptr->right = nullptr;
	return ptr;
}

void InOrder(Node *root) {
	if(root == nullptr)
	return;
	InOrder(root->left);
	cout<<root->data<<" ";
	InOrder(root->right);
}

Node* Construct(int start, int last, vector <int> preorder, int &pindex, unordered_map <int, int> &map) {
	if(start > last)
	return nullptr;
	
	Node* root = NewNode(preorder[pindex++]);
	int index = map[root->data];
	
	root->left = Construct(start, index-1, preorder, pindex, map);
	
	root->right = Construct(index+1, last, preorder, pindex, map);
	
	return root;
}

Node* ConstructBinaryTree(vector <int> inorder, vector <int> preorder) {
	int n = inorder.size();
	unordered_map <int, int> map;
	for(int i = 0; i<n; i++) {
		map[inorder[i]] = i;
	}
	
	int pindex = 0;
	
	return Construct(0, n-1, preorder, pindex, map);
}

int main() {
	vector <int> inorder = {4,2,1,7,5,8,3,6};
	vector <int> preorder = {1,2,4,3,5,7,8,6};
	root = ConstructBinaryTree(inorder, preorder);
	InOrder(root);
	return 0;
}
