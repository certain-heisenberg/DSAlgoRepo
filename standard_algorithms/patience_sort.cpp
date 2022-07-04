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
 
int h[maxN];
int a[maxN];
stack<int> dp[maxN];
map<int, int> par;

void pushFlower(int flower, int n){
	int low=1;
	int high=n;
	
	while(low<high){
		int mid=low+(high-low)/2;
		if(dp[mid].empty() || dp[mid].top()>flower) high=mid;
		else low=mid+1;
	}
	
	dp[low].push(flower);
	
	if(low==1) par[flower]=-1;
	else par[flower]=dp[low-1].top();
}

void getAns(int n){
	
	FOR(1, n){
		pushFlower(h[i], n);
	}
	
	FOR(1, n){
		if(dp[i].empty()) break;
		while(!dp[i].empty()){
			cout<<dp[i].top()<<" ";
			dp[i].pop();
		}
		cout<<endl;
	}
	
	cout<<endl;
	
	
	for(pi c: par){
		cout<<c.ff<<" "<<c.ss<<endl;
	}
}

void solve(){
	int n, x;
	cin>>n;
	
	FOR(1, n){
		cin>>x;
		h[i]=x;
	}
	
	FOR(1, n){
		cin>>x;
		a[i]=x;
	}
	
	getAns(n);
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
