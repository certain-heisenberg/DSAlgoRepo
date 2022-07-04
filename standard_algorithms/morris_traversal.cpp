#include <bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	Node *left, *right;
};

Node* getNode(int val){
	Node* res=new Node();
	res->val=val;
	res->left=NULL;
	res->right=NULL;
	return res;
}

Node* findPred(Node* R){
	Node* root=R->left;
	
	while(root->right && root->right!=R){
		root=root->right;
	}
	return root;
}

void morris_inorder(Node* R){	
	Node* root=R;
	
	while(root){
		if(root->left){
			Node* pred=findPred(root);
			if(pred->right==NULL){
				pred->right=root;
				root=root->left;
			}
			else{
				pred->right=NULL;
				cout<<root->val<<" ";
				root=root->right;
			}
		}
		else{
			cout<<root->val<<" ";
			root=root->right;
		}
	}
}

void morris_preorder(Node* R){
	Node* root=R;
	
	while(root){
		if(root->left){
			Node* pred=findPred(root);
			if(pred->right==NULL){
				pred->right=root;
				cout<<root->val<<" ";
				root=root->left;
			}
			else{
				pred->right=NULL;
				root=root->right;
			}
		}
		else{
			cout<<root->val<<" ";
			root=root->right;
		}
	}
}

int main(){
	Node* root;
	
	root=getNode(5);
	root->left=getNode(3);
	root->right=getNode(7);
	root->left->left=getNode(1);
	root->left->right=getNode(4);
	root->right->left=getNode(6);
	root->right->right=getNode(8);
	
	morris_inorder(root);
	cout<<endl;
	morris_preorder(root);
}
