#include <bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	Node* left;
	Node* right;
	int height;
};

Node* GetNewNode(int a){
	Node* x=new Node();
	x->val=a;
	x->left=NULL;
	x->right=NULL;
	x->height=1;
	return x;
}

int GetHeight(Node* root){
	if(root==NULL) return 0;
	return root->height;
}

Node* RightRotate(Node* root){
	Node* temp=root;
	temp=temp->left;
	
	//Rotation
	root->left=temp->right;
	temp->right=root;
	
	//Height updation
	root->height=max(GetHeight(root->left), GetHeight(root->right))+1;
	temp->height=max(GetHeight(temp->left), GetHeight(temp->right))+1;
	
	return temp;
}

Node* LeftRotate(Node* root){
	Node* temp=root;
	temp=temp->right;
	
	//Rotation
	root->right=temp->left;
	temp->left=root;
	
	//Height updation
	root->height=max(GetHeight(root->left), GetHeight(root->right))+1;
	temp->height=max(GetHeight(temp->left), GetHeight(temp->right))+1;
	
	return temp;
}

Node* insert(Node* root, int a){
	if(root==NULL){
		root=GetNewNode(a);
		return root;
	}
	
	if(a<=root->val) root->left=insert(root->left, a);
	else root->right=insert(root->right, a);
	
	root->height=max(GetHeight(root->left), GetHeight(root->right))+1;
	
	int dif=GetHeight(root->left)-GetHeight(root->right);
	
	if(dif>1){
		if(GetHeight(root->left->left)>=GetHeight(root->left->right)){
			root=RightRotate(root);
		}
		else{
			root->left=LeftRotate(root->left);
			root=RightRotate(root);
		}
	}
	if(dif<-1){
		if(GetHeight(root->right->right)>=GetHeight(root->right->left)){
			root=LeftRotate(root);
		}
		else{
			root->right=RightRotate(root->right);
			root=LeftRotate(root);
		}
	}
	
	return root;
}

void preorder(Node* root){
	if(root==NULL) return;
	
	cout<<root->val<<" ";
	preorder(root->left);
	preorder(root->right);
}

int main(){
	
	vector<int> v={12, 25, 26, 28, 32, 11, 10};
	
	Node* root=NULL;
	
	for(int c: v){
		root=insert(root, c);
	}
	
	preorder(root);
}

/*
NOTE TO READER:
 - Difference of height of left or right subtree cannot be greater than one.
 
 - There are four different use cases to insert into AVL tree:
   (1) left left - needs ones right rotation
   (2) left right - needs one left and one right rotation
   (3) right left - needs one right and one left rotation
   (4) right right - needs one left rotation
   
 - Follow rotation rules to keep tree balanced.
  
 - At every node we will also keep height of the tree so that we don't have to
   recalculate values again.
  
   Runtime complexity to insert into self-balancing BST is O(logn).
*/
