#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

struct TrieNode{
	map<char, TrieNode*> child;
	bool isEnd;
};

TrieNode* GetNewNode(){
	TrieNode* x=new TrieNode();
	x->child.clear();
	x->isEnd=false;
	return x;
}

/* Inserts a string "s" into the trie */
TrieNode* insert(string s, TrieNode* root){
	TrieNode* x=root;
	
	for(int i=0; i<s.size(); i++){
		map<char, TrieNode*> &mp=x->child;
		if(mp.find(s[i])==mp.end()){
			mp[s[i]]=GetNewNode();
		}
		x=mp[s[i]];
	}
	
	x->isEnd=true;
	return root;
}

/* Returns true if the string "s" is in the trie */
bool search(string s, TrieNode* root){
	TrieNode* x=root;
	
	for(int i=0; i<s.size(); i++){
		map<char, TrieNode*> &mp=x->child;
		if(mp.find(s[i])==mp.end()){
			return false;
		}
		x=mp[s[i]];
	}
	
	return x->isEnd;
}

/* Returns true if there is any string in the trie 
   that starts with the given prefix string "s" */
bool startsWith(string s, TrieNode* root){
	TrieNode* x=root;
	
	for(int i=0; i<s.size(); i++){
		map<char, TrieNode*> &mp=x->child;
		if(mp.find(s[i])==mp.end()){
			return false;
		}
		x=mp[s[i]];
	}
	
	return true;
} 


int main(){
	TrieNode* root=GetNewNode();
	
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
