#include <bits/stdc++.h>
using namespace std;
 
#define kk
//#define int long long
#define FOR(a, b) for(int i=a; i<=b; i++)
#define REP(i, a, b) for(int i=a; i<=b; i++)
#define ff first
#define ss second
#define ll long long
#define inf 1000000000
#define pb push_back
#define mod 1000000007
 
const ll INF=1e18+5;
typedef pair<int, int> pi;

bool arr[10][100];
int dp[100][1<<10];

int bitmask(int mask, int shirt, int& n){
	if(mask==0) return 1;
	
	if(shirt==100) return 0;
	
	if(dp[shirt][mask]!=-1) return dp[shirt][mask];
	
	int ans=0;
	for(int person=0; person<n; person++){
		if(mask & (1<<person)){
			if(arr[person][shirt]){
				ans=ans%mod+bitmask(mask ^ (1<<person), shirt+1, n)%mod;
			}
		}
	}
	
	ans=ans%mod+bitmask(mask, shirt+1, n)%mod;
	
	return dp[shirt][mask]=ans%mod;
}

void solve(){
	int n;
	cin>>n;
	cin.ignore();
	
	string s;
	
	for(int i=0; i<n; i++){
		getline(cin, s);
		stringstream ss(s);
        int a;
        while(ss>>a){
            arr[i][a-1]=1;
        }
	}
	
	memset(dp, -1, sizeof dp);
		
	int mask=(1<<n)-1;
	
	cout<<bitmask(mask, 0, n)<<endl;
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
		memset(arr, 0, sizeof arr);
		
		solve();
	}
}
