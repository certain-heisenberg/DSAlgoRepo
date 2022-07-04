#include <bits/stdc++.h>
using namespace std;
 
//#define kk
//#define int long long
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
#define endl "\n"
 
const ll INF=1e18+5;
const int maxN=1e5+5;
typedef pair<int, int> pi;

struct node{
	int t, x, y;
};

node arr[maxN];
int dp[maxN];
int max_dp[maxN];

void solve(){
	int r, n;
	cin>>r>>n;
	
	for(int i=1; i<=n; i++){
		cin>>arr[i].t>>arr[i].x>>arr[i].y;
	}
	
	arr[0].t=0, arr[0].x=1, arr[0].y=1;
	
	for(int i=1; i<=n; i++){
		dp[i]=INT_MIN;
		for(int j=max(0, i-2*r); j<i; j++){
			int a=abs(arr[i].x-arr[j].x);
			int b=abs(arr[i].y-arr[j].y);
			if(arr[i].t-arr[j].t>=a+b){
				dp[i]=max(dp[i], dp[j]+1);
			}
		}
		if(i>2*r) dp[i]=max(dp[i], 1+max_dp[i-2*r]);
		max_dp[i]=max(dp[i], max_dp[i-1]);
	}
	cout<<max_dp[n]<<endl;
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
