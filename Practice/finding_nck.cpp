#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void comb_m1(){
	int n=26, k=5;
	
	for(int i=0; i<n-k; i++) s.push_back('0');
	
	for(int i=0; i<k; i++) s.push_back('1');
	
	do{
		vector<int> v;
		
		for(int i=0; i<n; i++){
			if(s[i]=='1') v.push_back(i+1);
		}
		ans.push_back(v);
		
	}while(next_permutation(s.begin(), s.end()));
}

void comb_m2(int k, int left, int n, vector<int> v){
	if(k==0){
		ans.push_back(v);
		return;
	}
	
	for(int i=left; i<=n; i++){
		v.push_back(i);
		comb_m2(k-1, left, n, v);
		v.pop_back();
	}
}

int main(){
	#ifndef kk
	//freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
		
	//comb_m1();
	
	comb_m2(5, 1, 26, {});
}
