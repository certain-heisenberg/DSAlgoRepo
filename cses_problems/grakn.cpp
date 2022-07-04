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
const int maxN=105;
typedef pair<int, int> pi;

int a[maxN], b[maxN], c[maxN];

void solve(){
	int n;
	cin>>n;
	
	FOR(1, n) cin>>a[i];
	FOR(1, n) cin>>b[i];
	FOR(1, n) cin>>c[i];
	
	cout<<a[1]<<" ";
	
	int l=a[1];
	int k=a[1];
	
	FOR(2, n-1){
		if(k!=a[i]){
			cout<<a[i]<<" ";
			k=a[i];
		}
		else if(k!=b[i]){
			cout<<b[i]<<" ";
			k=b[i];
		}
		else{
			cout<<c[i]<<" ";
			k=c[i];
		}
	}
	
	if(k!=a[n] && a[n]!=l){
		cout<<a[n]<<" ";
	}
	else if(k!=b[n] && b[n]!=l){
		cout<<b[n]<<" ";
	}
	else if(c[n]!=l){
		cout<<c[n]<<" ";
	}
	cout<<endl;
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
	
	while(T--){		
		solve();
	}
}

