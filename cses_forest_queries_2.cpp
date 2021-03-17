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
const int maxN=2e5+5;
typedef pair<int, int> pi;

int arr[1005][1005];
int dp[1005][1005];

void build_dp(int n){
	
	FOR(1, n){
		REP(j, 1, n){
			dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+arr[i][j];
		}
	}
	
}

void solve(){
	int n, q;
	cin>>n>>q;
	
	FOR(1, n){
		REP(j, 1, n){
			char c;
			cin>>c;
			arr[i][j]=c=='*' ? 1 : 0;
		}
	}
	
	build_dp(n);
	
	int c;
	
	while(q--){
		cin>>c;
		if(c==1){
			int x, y;
			cin>>x>>y;
			
		}
		else{
			int x1, y1, x2, y2;
			cin>>x1>>y1>>x2>>y2;
			
		}
	}
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



