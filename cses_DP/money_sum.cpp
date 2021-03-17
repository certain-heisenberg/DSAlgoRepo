#include <bits/stdc++.h>
using namespace std;
 
//#define kk
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

int coins[105];
bool dp[105][maxN];

void solve(){
	int n;
	cin>>n;
	
	int S=0;
	FOR(1, n) cin>>coins[i], S+=coins[i];

	FOR(0, n) dp[i][0]=1;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=S; j++){
			if(coins[i]<=j){
				dp[i][j]=dp[i-1][j] || dp[i-1][j-coins[i]];
			}
			else dp[i][j]=dp[i-1][j];
		}
	}
	
	int cnt=0;
	for(int i=1; i<=S; i++) if(dp[n][i]) cnt++;
	cout<<cnt<<endl;
	
	for(int i=1; i<=S; i++) if(dp[n][i]) cout<<i<<" ";
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

