#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll int
typedef pair<int, int> pi;

int arr[50];

bool solve(map<int, int> &mp, int sum, int &num){
	
	if(sum==0) return true;
	
	for(pi p: mp){
		if(p.second){
			mp[p.first]--;
			num++;
			if(solve(mp, sum-p.first, num)) return true;
		}
	}
	return false;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
    #endif
	
	int T;
	int cnt=0;
	while(1){
		string s;
		getline(cin, s);
		if(s=="") break;
		//if(s=="") cnt++;
		//else cnt=0;
		
		map<int, int> mp;
		
		for(int i=1; i<=6; i++) mp[i]=4;
		
		int sum=31, n=0;
		for(char c: s) mp[c-'0']--, sum-=c-'0', n++;
		
		if(sum==0){
			if(n%2) cout<<s<<" A"<<endl;
			else cout<<s<<" B"<<endl;
		}
		else{
			int num=0;
			if(solve(mp, sum, num)){
				if((n+num)%2) cout<<s<<" B"<<endl;
				else cout<<s<<" B"<<endl;
			}
		}
		
	}
	
}
