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
#define pi pair<int, int>
#define inf 1000000000
#define mod 1000000007
#define endl "\n"

const ll INF=1e18+5;
const int maxN=1e6+5;

const int M=1e5+5;
int fact[M], inv_fact[M];

int power(int a, int n){
	int res=1;
	
	while(n){
		if(n%2) res=(res*a)%mod, n--;
		else a=(a*a)%mod, n/=2;
	}
	return res;
}

void init(){
	fact[0]=inv_fact[0]=1;
	
	for(int i=1; i<M; i++){
		fact[i]=(i*fact[i-1])%mod;
		inv_fact[i]=power(fact[i], mod-2)%mod;
	}
}

int combinator(int a, int b){
	if(a<0 || b<0 || a<b) return 0;
	
	return (fact[a]%mod*inv_fact[b]%mod*inv_fact[a-b]%mod)%mod;
}

void solve(){
	int n, k;
	cin>>n>>k;
	
	vector<int> arr(n+1);
	
	FOR(1, n) cin>>arr[i];
	
	
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

