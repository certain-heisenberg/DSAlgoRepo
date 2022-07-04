#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define mat vector<vector<int>>
#define vi vector<int>
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define pi pair<int, int>
#define inf 1000000000
#define mod 1000000007
#define rep(i,a,b) for(int i=a; i<b; i++)
#define rrep(i,a,b) for(int i=b; i>=a; i--)
//#define endl "\n"

//****DO NOT TOUCH ABOVE THIS LINE****//
#define kk

const int maxN=5e4+5;

vector<vector<int>> arr[maxN];

map<int, vector<pair<int, pi>>> path;
vector<pair<int, pi>> tpath;

void dfs(int v, int p){
	
	for(vector<int> c: arr[v]){
		int u=c[0];
		int l=c[1];
		int a=c[2];
		if(u!=p){
			tpath.pb({u,{l,a}});
			path[u]=tpath;
			dfs(u,v);
			tpath.pop_back();
		}
	}
}

void solve(){
	int n,q;
	cin>>n>>q;
	
	path.clear();
	tpath.clear();
	
	rep(i,1,n+1) arr[i].clear();
	
	rep(i, 1, n){
		int one,two,three,four;
		cin>>one>>two>>three>>four;
		
		arr[one].pb({two,three,four});
		arr[two].pb({one,three,four});
	}
	
	dfs(1, -1);
	
	while(q--){
		int st,wt;
		cin>>st>>wt;
		
		int ans=0;
		
		for(auto p: path[st]){
			if(wt>=p.ss.ff) ans=__gcd(ans, p.ss.ss);
		}
		
		cout<<ans<<" ";
	}
	cout<<endl;
}

//****DO NOT TOUCH BELOW THIS LINE****//

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cout<<fixed<<setprecision(5);

	#ifdef kk
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif
	
	int T=1;
	cin>>T;
	
	int i=1;

	while(i<=T){
		cout<<"Case #"<<i<<": ";
		solve();
		i++;
	}
}
