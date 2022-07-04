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

string X, Y;

int dp[5005][5005];

int getAns(int n, int m){
	if(X==Y) return 0;
	
	if(n==-1) return m+1;
	if(m==-1) return n+1;
	
	if(dp[n][m]!=-1) return dp[n][m];
	
	if(X[n]==Y[m]){
		return dp[n][m]=getAns(n-1, m-1);
	}
	else{
		return dp[n][m]=1+min({getAns(n-1, m), getAns(n, m-1), getAns(n-1, m-1)});
	}
}

void solve(){
	cin>>X>>Y;
	int n=X.size()-1, m=Y.size()-1;
	
	memset(dp, -1, sizeof dp);
	
	cout<<getAns(n, m)<<endl;
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

