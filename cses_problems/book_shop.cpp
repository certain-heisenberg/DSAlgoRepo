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

int price[1005];
int pages[1005];

int dp[1005][maxN];

void solve(){
	int n, P;
	cin>>n>>P;
	
	FOR(1, n) cin>>price[i];
	FOR(1, n) cin>>pages[i];
	
	// dp[i][j] - maximum number of pages we can buy with price "j" taking books upto index "i"
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=P; j++){
			if(price[i]<=j){
				dp[i][j]=max(dp[i-1][j], pages[i]+dp[i-1][j-price[i]]);
			}
			else dp[i][j]=dp[i-1][j];
		}
	}
	
	cout<<dp[n][P]<<endl;
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

