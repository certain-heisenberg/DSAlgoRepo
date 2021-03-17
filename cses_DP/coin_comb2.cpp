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
 
const ll INF=1e18+5;
const int maxN=1e6+5;
typedef pair<int, int> pi;

int dp[105][maxN];

void solve(){
	int n, s;
	cin>>n>>s;
	
	vector<int> coins(n);
	FOR(1, n) cin>>coins[i];
	
	for(int i=0; i<=n; i++){
		dp[i][0]=1;
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=s; j++){
			if(coins[i]<=j){
				dp[i][j]=(dp[i-1][j]%mod+dp[i][j-coins[i]]%mod)%mod;
			}
			else dp[i][j]=dp[i-1][j];
		}
	}
	
	cout<<dp[n][s]%mod<<endl;
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

