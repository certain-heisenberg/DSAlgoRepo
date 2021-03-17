#include <bits/stdc++.h>
using namespace std;
 
#define kk
#define int long long
#define FOR(a, b) for(int i=a; i<=b; i++)
#define REP(i, a, b) for(int i=a; i<=b; i++)
#define mat vector<vector<int>>
#define vi vector<int>
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define inf 1000000000
#define mod 1000000007
#define endl "\n"

const ll INF=1e18+5;
const int maxN=3e5+5;
typedef pair<int, int> pi;

vector<int> arr[maxN];
int vis[maxN];

// for checking cycle in an undirected graph
bool dfs(int v, int p){
	vis[v]=1;
	
	for(int child: arr[v]){
		if(vis[child]==0){
			bool res=dfs(child, v);
			if(res==true) return true;
		}
		else if(child!=p) return true;
	}
	
	return false;
}

// for checking cycle in a directed graph
bool dfs(int v){
	vis[v]=1;
    
    for(int child: arr[v]){
        if(vis[child]==0){
			bool res=dfs(child);
            if(res==true) return true;
        }
        else if(vis[child]==1) return true;
    }
    
    vis[v]=2;
    return false;
}


void solve(){
	int n, m;
	cin>>n>>m>>s;
	
	FOR(1, m){
		int a, b;
		cin>>a>>b;
		arr[a].pb(b);
		arr[b].pb(a);
	}
	
	cout<<dfs(1, -1)<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cout<<fixed<<setprecision(6);
	
	#ifdef kk
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int T=1;
	//cin>>T;

	while(T--){		
		solve();
	}
}

