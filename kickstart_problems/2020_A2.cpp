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
const int maxN=1e6+5;
typedef pair<int, int> pi;

void solve(){
	int n, k, p;
	cin>>n>>k>>p;
	
	vector<vector<int>> arr(n+1, vector<int> (k+1));
	
	FOR(1, n){
		REP(j, 1, k){
			cin>>arr[i][j];
		}
	}
	
	vector<vector<int>> dp(n+1, vector<int> (p+1));
	
	for(int i=1; i<=n; i++){
		for(int j=2; j<=k; j++){
			arr[i][j]+=arr[i][j-1];
		}
	}
	
    // dp[i][j] - max beauty value if we take exactly "j" plates from stack of plates upto index "i"  
	
	// To take out "j" plates from stack of plates upto index "i", we can do the following :-
	// Take 0 plates from ith stack + j plates from rest (i-1) stacks
	// Take 1 plate from ith stack + j-1 plates from rest (i-1) stacks 
	// and so on...
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=p; j++){
			for(int l=0; l<=j; l++){
				if(l<=k) dp[i][j]=max(dp[i][j], dp[i-1][j-l]+arr[i][l]);
			}
		}
	}
	cout<<dp[n][p]<<endl;

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
	cin>>T;

	int i=1;	
	while(i<=T){		
		cout<<"Case #"<<i<<": ";
		solve();
		i++;
	}
}

