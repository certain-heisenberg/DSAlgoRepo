#include <bits/stdc++.h>
using namespace std;
 
#define kk
#define int long long
#define FOR(a, b) for(int i=a; i<=b; i++)
#define REP(i, a, b) for(int i=a; i<=b; i++)
#define ff first
#define ss second
#define ll long long
#define inf 1000000000
#define pb push_back
#define mod 1000000007
 
const ll INF=1e18+5;
const int maxN=2e5+5;
typedef pair<int, int> pi;
 
vector<int> arr[maxN];

int dp1[maxN], dp2[maxN];

void eval_dp1(int v, int p, int k){
	if(k==0){
		dp1[v]=1;
		return;
	}
	
	int ans=0;
	for(int child: arr[v]){
		if(child!=p){
			eval_dp1(child, v, k-1);
			ans+=dp1[child];
		}
	}
	
	dp1[v]=ans;
}

void eval_dp2(int v, int p, int k){
	if(k==0){
		dp1[v]=1;
		return;
	}
	
	int ans=0;
	for(int child: arr[v]){
		if(child!=p){
			eval_dp1(child, v, k-1);
			ans+=dp1[child];
		}
	}
	
	dp1[v]=ans;
} 

void solve(){
	int n, k;
	cin>>n>>k;
	
	FOR(1, n-1){
		int a, b;
		cin>>a>>b;
		arr[a].pb(b);
		arr[b].pb(a);
	}
	
	eval_dp1(1, -1, k);
	
	FOR(1, n) cout<<dp1[i]<<" ";
	
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
