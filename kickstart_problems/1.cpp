#include <bits/stdc++.h>
using namespace std;
 
#define kk
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
#define endl "\n"

const ll INF=1e18+5;

const int naxN=1e2+5;
int fact[naxN], inv_fact[naxN];

int power(int a, int n){
	int res=1;
	
	while(n){
		if(n%2) res=(res*a)%mod, n--;
		else a=(a*a)%mod, n/=2;
	}
	return res;
}

void init(){
	fact[0]=inv_fact[0]=1;
	
	for(int i=1; i<naxN; i++){
		fact[i]=(i*fact[i-1])%mod;
		inv_fact[i]=power(fact[i], mod-2)%mod;
	}
}

int ncr(int a, int b){
	if(a<0 || b<0 || a<b) return 0;
	
	return (fact[a]%mod*inv_fact[b]%mod*inv_fact[a-b]%mod)%mod;
}

//****DO NOT TOUCH ABOVE THIS LINE****//

const int maxN=1e5+5;

vector<int> arr[50005];
int dp1[50005][505];
int dp2[50005][505];

int n, k;
int res;
 
void dfs1(int v, int p){
	
	for(int child: arr[v]){
		if(child!=p){
			dfs1(child, v);
		}
	}
	
	dp1[v][0]=1;
	
	for(int d=1; d<=k; d++){
		dp1[v][d]=0;
		for(int child: arr[v]){
			if(child!=p){
				dp1[v][d]+=dp1[child][d-1];
			}
		}
	}
}
 
void dfs2(int v, int p){
	
	for(int d=0; d<=k; d++){
		dp2[v][d]=dp1[v][d];
	}
	
	if(p!=-1){
		dp2[v][1]+=dp2[p][0]; //for counting all nodes in the whole tree at distance 1 from node v
		
		for(int d=2; d<=k; d++){
			dp2[v][d]+=dp2[p][d-1];
			dp2[v][d]-=dp1[v][d-2];
		}
	}
	
	//calculating dp2 values for child nodes
	for(int child: arr[v]){
		if(child!=p){
			dfs2(child, v);
		}
	}
}

void solve(){
	cin>>n>>k;
	
	for(int i=1; i<n; i++){
		int a, b;
		cin>>a>>b;
		arr[a].pb(b);
		arr[b].pb(a);
	}
	
	dfs1(1, -1);
	dfs2(1, -1);
	
	for(int i=1; i<=n; i++){
		res+=dp2[i][k];
	}
	
	res/=2;
	
	cout<<res<<endl;
}

//****DO NOT TOUCH BELOW THIS LINE****//

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

