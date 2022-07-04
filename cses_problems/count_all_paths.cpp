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

vector<vector<int>> paths;
vector<int> temp_path;

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
}

int get_path_count(int n){
	vector<int> dp(n+1, 0);
	
	for(int i=n-1; i>=0; i--){
		for(int child: arr[res[i]]){
			dp[res[i]]+=dp[child]+1;
		}
	}
	
	int ans=0;
	
	for(int i=1; i<=n; i++) ans+=dp[i];
	
	return ans;
}

void dfs(int v){
	temp_path.pb(v);
	if(temp_path.size()>1) paths.pb(temp_path);
	
	for(int child: arr[v]){
		dfs(child);
	}
	
	temp_path.pop_back();
}

void get_paths(int n){
	for(int i=0; i<n; i++){
		dfs(res[i]);
	}
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
	
	cout<<"Count of all the paths in the given DAG is: ";
	cout<<get_path_count(n)<<endl<<endl;
	
	get_paths(n);
	
	cout<<"List of all the paths are: "<<endl;
	for(vector<int> v: paths){
		for(int c: v) cout<<c<<" ";
		cout<<endl;
	}
}
 
signed main(){
	int T=1;
	//cin>>T;
	
	while(T--){		
		solve();
	}
}
