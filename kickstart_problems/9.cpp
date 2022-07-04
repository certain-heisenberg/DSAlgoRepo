#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define mat vector<vector<int>>
#define vi vector<int>
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define pi pair<int, int>
#define inf 1000000000
#define mod 998244353
#define endl "\n"

const ll INF=1e18+5;

const int naxN=30;
int fact[naxN], inv_fact[naxN];

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
	
	for(int i=1; i<naxN; i++){
		fact[i]=(i*fact[i-1])%mod;
		inv_fact[i]=power(fact[i], mod-2)%mod;
	}
}

int ncr(int a, int b){
	if(a<0 || b<0 || a<b) return 0;

	return (fact[a]%mod*inv_fact[b]%mod*inv_fact[a-b]%mod)%mod;
}

//int dx[8]={-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8]={-1, 0, 1, 1, 1, 0, -1, -1};

int par[30];
int R[30];

int find(int a){
	if(par[a]<0) return a;
	return par[a]=find(par[a]);
}

void merge(int a, int b){
	a=find(a);
	b=find(b);
	
	if(a==b) return;
	
	if(R[a]>=R[b]){
		par[b]=a;
		R[a]+=R[b];
	}
	else{
		par[a]=b;
		R[b]+=R[a];
	}
}

const int naxP=2;

int prime[naxP];

void sieve(){
    prime[0]=1;
    prime[1]=1;

    for(int i=2; i*i<=naxP; i++){
        if(prime[i]==0){
            for(int j=i*i; j<=naxP; j+=i){
                prime[j]=1;
            }
        }
    }
}

//****DO NOT TOUCH ABOVE THIS LINE****//
//#define kk

const int maxN=2e5+5;

void solve(){
	int a, b, k;
	cin>>a>>b>>k;
	
	vector<pi> arr(k);
	
	for(int i=0; i<n; i++) cin>>arr[i].ff;
	
	for(int i=0; i<n; i++) cin>>arr[i].ss;
	
	int cnt=0;
	
	
	cout<<cnt<<endl;
}

//****DO NOT TOUCH BELOW THIS LINE****//

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cout<<fixed<<setprecision(6);
	
	#ifdef kk
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif
	
	int T=1;
	cin>>T;

	while(T--){		
		solve();
	}
}
