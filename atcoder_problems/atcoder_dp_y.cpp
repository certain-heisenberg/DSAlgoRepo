#include <bits/stdc++.h>
using namespace std;
 
//#define kk
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

int fact[maxN], inv_fact[maxN];

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
	
	for(int i=1; i<maxN; i++){
		fact[i]=(i*fact[i-1])%mod;
		inv_fact[i]=power(fact[i], mod-2)%mod;
	}
}

int combinator(int a, int b){
	if(a<0 || b<0 || a<b) return 0;
	
	return (fact[a]%mod*inv_fact[b]%mod*inv_fact[a-b]%mod)%mod;
}

void solve(){
	int h, w, n;
	cin>>h>>w>>n;
	
	vector<pi> arr(n);
	
	for(int i=0; i<n; i++){
		int a,b;
		cin>>a>>b;
		arr[i]={a-1,b-1};
	}
	arr.pb({h-1, w-1});
	
	sort(arr.begin(), arr.end(), [](pi a, pi b){
		return a.ff+a.ss<b.ff+b.ss;
		});
		
	init();
	
	vector<int> dp(n+1, 0);
	
	for(int i=0; i<=n; i++){
		int a=arr[i].ff, b=arr[i].ss;
		int f=combinator(a+b, b);
		
		for(int j=0; j<i; j++){
			int c=arr[j].ff, d=arr[j].ss;
			if(c<=a && d<=b){
				f=(f-((dp[j]*combinator(a-c+b-d, b-d))%mod)+mod)%mod;
			}
		}
		dp[i]=f;
	}
	cout<<dp[n]<<endl;
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
