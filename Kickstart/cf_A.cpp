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
#define endl "\n"
 
const ll INF=1e18+5;
typedef pair<int, int> pi;

//****DO NOT TOUCH ABOVE THIS LINE****//

const int maxN=2e5+5;

vector<int> arr[maxN];
int a[maxN];

void solve(){
	int n, p;
	cin>>n;
	
	for(int i=2; i<=n; i++){
		cin>>p;
		arr[p].pb(i);
	}
	
	for(int i=1; i<=n; i++) cin>>a[i];
}

//****DO NOT TOUCH BELOW THIS LINE****//

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
