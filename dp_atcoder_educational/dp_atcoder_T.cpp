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

int dp[3005][3005];

int n;
string s;

void solve(){
	cin>>n;
	cin>>s;
	
	// dp[len][j] - no. of permutations in prefix of size "len" such that the last number
	// (or {len}-th number) is "j" 
	
	dp[1][1]=1;
	
	for(int len=2; len<=n; len++){
		for(int j=1; j<=len; j++){
			int L, R;
			
			if(s[len-2]=='<') L=1, R=j-1;
			else L=j, R=len-1;
			
			if(L<=R) dp[len][j]=(dp[len][j]+(dp[len-1][R]-dp[len-1][L-1]+mod))%mod;
		}
		
		if(len!=n){
			for(int j=1; j<=len; j++){
				dp[len][j]=(dp[len][j]+dp[len][j-1])%mod;
			}
		}
	}
	
	int ans=0;
	
	for(int i=1; i<=n; i++){
		ans=(ans+dp[n][i])%mod;
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
