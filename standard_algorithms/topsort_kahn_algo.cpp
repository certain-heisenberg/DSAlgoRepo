// Input:-
// 6 10
// 1 2
// 2 3
// 1 4
// 2 4
// 3 4
// 5 6
// 4 6
// 3 5
// 4 5
// 3 6

#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define pb push_back

vector<int> arr[1005];
vector<int> indegree(1005);
vector<int> res;

void kahn(int n){
	queue<int> q;
	
	for(int i=1; i<=n; i++){
		if(indegree[i]==0) q.push(i);
	}
	
	while(!q.empty()){
		int v=q.front();
		q.pop();
		res.pb(v);
		
		for(int child: arr[v]){
			indegree[child]--;
			if(indegree[child]==0) q.push(child);
		}
	}
	
	cout<<"Topological sort of the given graph is:"<<endl;
	
	for(int c: res) cout<<c<<" ";
}

void solve(){
	int n, m, a, b;
	cin>>n>>m;
	
	for(int i=1; i<=m; i++){
		cin>>a>>b;
		arr[a].pb(b);
		indegree[b]++;
	}
	
	kahn(n);
}
 
signed main(){
	int T=1;
	//cin>>T;
	
	while(T--){		
		solve();
	}
}
