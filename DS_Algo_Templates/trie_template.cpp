#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

struct TrieNode{
	// array implementation for child list is faster than its std::map imlementaion
	TrieNode* childList[26]={NULL}; 
	bool isWordEnd=false;
};

/* Inserts a string "s" into the trie */
TrieNode* insert(string s, TrieNode* root){
	TrieNode* curNode=root;
	
	for(int i=0; i<s.size(); i++){
		int k=s[i]-'a';
		TrieNode** childList=curNode->childList;
		if(childList[k]==NULL){
			childList[k]=new TrieNode();
		}
		curNode=childList[k];
	}
	
	curNode->isWordEnd=true;
	return root;
}

/* Returns true if the string "s" is in the trie */
bool search(string s, TrieNode* root){
	TrieNode* curNode=root;
	
	for(int i=0; i<s.size(); i++){
		int k=s[i]-'a';
		TrieNode** childList=curNode->childList;
		if(childList[k]==NULL){
			return false;
		}
		curNode=childList[k];
	}
	
	return curNode->isWordEnd;
}

/* Returns true if there is any string in the trie 
   that starts with the given preficurNode string "s" */
bool startsWith(string s, TrieNode* root){
	TrieNode* curNode=root;
	
	for(int i=0; i<s.size(); i++){
		int k=s[i]-'a';
		TrieNode** childList=curNode->childList;
		if(childList[k]==NULL){
			return false;
		}
		curNode=childList[k];
	}
	
	return true;
} 


int main(){
	TrieNode* root=new TrieNode();
	
	vector<string> v={"apple", "application", "ballboy", "baller", "geany"};
	
	for(auto c: v){
		root=insert(c, root);
	}
	
	cout<<search("ballboy", root)<<endl;
	cout<<search("ball", root)<<endl;
	
	cout<<startsWith("ball", root)<<endl;
}

/* NOTE TO READER: 
  - Above is the implementation of Trie Data Structure which can also be
    used for creating dictionary and searching for other characters along 
    with alphabets. It can also be used to search for any word that start 
    with given prefix. Node of the Trie Data structure is implemented using
    "map" instead of "array".     
*/
