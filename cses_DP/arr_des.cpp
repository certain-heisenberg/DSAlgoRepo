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
const int maxN=1e5+5;
typedef pair<int, int> pi;
 
int arr[maxN];
int dp[maxN][105];

void solve(){
	int n, m;
	cin>>n>>m;
	
	FOR(1, n) cin>>arr[i];
	
	// dp[i][j] = no. of ways to fill array upto index "i" if element at "ith" index
	//            in the array is "j" 
	
	int v=arr[1];
	if(v==0){
		for(int i=1; i<=m; i++) dp[1][i]=1;
	}
	else dp[1][v]=1;
	
	for(int i=2; i<=n; i++){
		v=arr[i];
		if(v==0){
			for(int j=1; j<=m; j++){
				for(int k: {j-1, j, j+1}){
					if(1<=k && k<=m){
						(dp[i][j]+=dp[i-1][k])%=mod;
					}
				}
			}
		}
		else{
			for(int k: {v-1, v, v+1}){
				if(1<=k && k<=m){
					(dp[i][v]+=dp[i-1][k])%=mod;
				}
			}
		}
	}
	
	int ans=0;
	
	FOR(1, m){
		(ans+=dp[n][i])%=mod;
	}
	
	cout<<ans<<endl;
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

