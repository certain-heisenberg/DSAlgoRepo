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

int arr[16][16];
int dp[16][1<<16];

int bitmask(int i, int mask, int &n){
	if(i==n) //do something
	
	for(int k=0; k<n; k++){
		if(mask & (1<<k)){
			bitmask(i+1, mask^(1<<k), n);
		}
	}
	
	
}

void solve(){
	int n;
	cin>>n;
	
	FOR(1, n){
		REP(j, 1, n){
			cin>>arr[i-1][j-1];
		}
	}
	
	memset(dp, -1, sizeof dp);
	
	int mask=(1<<n)-1;
	
	int res=bitmask(0, mask, n);
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
