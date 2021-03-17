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
const int maxN=1e3+5;
typedef pair<int, int> pi;

struct block{
	int w;
	int s;
	int v;
};

block arr[maxN];
set<int> bk;
int ans;

void backtrack(int wt, int sd, int val, int n){
	ans=max(ans, val);
	int i;
	for(i=1; i<=n; i++){
		if(bk.find(i)==bk.end() && arr[i].s>=wt){
			bk.insert(i);
			backtrack(wt+arr[i].w, sd+arr[i].s, val+arr[i].v, n);
			bk.erase(i);
		}
	}
	
	if(i==n+1) return;
}

void solve(){
	int n, a, b, c;
	cin>>n;
	
	FOR(1, n){
		cin>>a>>b>>c;
		arr[i].w=a, arr[i].s=b, arr[i].v=c;
	}
	
	FOR(1, n){
		bk.insert(i);
		backtrack(arr[i].w, arr[i].s, arr[i].v, n);
		bk.erase(i);
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

