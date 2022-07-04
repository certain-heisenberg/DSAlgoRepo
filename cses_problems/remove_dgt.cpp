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
const int maxN=1e6+5;
typedef pair<int, int> pi;

char arr[1005][1005];
int dp[1005][1005];

void solve(){
	int n;
	cin>>n;
	
	FOR(1, n){
		REP(j, 1, n){
			cin>>arr[i][j];
		}
	}
	
	if(arr[n][n]=='.') dp[n][n]=1;
	else dp[n][n]=0;
	
	for(int i=n-1; i>=1; i--){
		if(arr[i][n]=='*') dp[i][n]=0;
		else dp[i][n]=dp[i+1][n];
		
		if(arr[n][i]=='*') dp[n][i]=0;
		else dp[n][i]=dp[n][i+1];
	}
	
	for(int i=n-1; i>=1; i--){
		for(int j=n-1; j>=1; j--){
			if(arr[i][j]=='.') dp[i][j]=(dp[i+1][j]%mod+dp[i][j+1]%mod)%mod;
		}
	}
	
	cout<<dp[1][1]%mod<<endl;
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

