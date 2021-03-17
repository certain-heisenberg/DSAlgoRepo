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

int arr[5005];
int dp[5005][5005];

int getAns(int s, int e){
	if(s==e) return arr[s];
	
	if(dp[s][e]!=-1) return dp[s][e];
	
	return dp[s][e]=max(arr[s]-getAns(s+1, e), arr[e]-getAns(s, e-1));
}

void solve(){
	int n;
	cin>>n;
	
	int S=0;
	FOR(1, n) cin>>arr[i], S+=arr[i];
	
	memset(dp, -1, sizeof dp);
	
	cout<<(S+getAns(1, n))/2<<endl;
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

