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
const int maxN=1e5+5;
typedef pair<int, int> pi;

void mul(mat &A, mat &B, int n){
	mat res(n, vi (n));
	
	FOR(0, n-1){
		REP(j, 0, n-1){
			REP(k, 0, n-1){
				res[i][j]=(res[i][j]%mod+(A[i][k]*B[k][j])%mod)%mod;
			}
		}
	}
	
	FOR(0, n-1){
		REP(j, 0, n-1){
			A[i][j]=res[i][j]%mod;
		}
	}
}

void solve(){
	int n, k;
	cin>>n>>k;
	
	mat arr(n, vi (n));
	
	FOR(0, n-1){
		REP(j, 0, n-1){
			cin>>arr[i][j];
		}
	}
	
	mat dp(n, vi(n));
	
	FOR(0, n-1){
		dp[i][i]=1;
	}
	
	while(k){
		if(k%2) mul(dp, arr, n), k--;
		else mul(arr, arr, n), k/=2;
	}
	
	int ans=0;
	FOR(0, n-1){
		REP(j, 0, n-1){
			ans=(ans+dp[i][j])%mod;
		}
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

