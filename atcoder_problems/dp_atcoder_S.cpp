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
const int maxN=1e5+5;
typedef pair<int, int> pi;

const int nax1=1e4+5;
const int nax2=1e2+5;

vector<int> num;
int dp[nax1][2][nax2];

int d;

int call(int pos, int flag, int sum){
	if(pos==(int)num.size()) return sum==0;
	
	if(dp[pos][flag][sum]!=-1) return dp[pos][flag][sum];
	
	int limit;
	if(flag==0) limit=num[pos];
	else limit=9;
	
	int res=0;
	
	for(int i=0; i<=limit; i++){
		int f=flag;
		if(i<limit) f=1;
		res=(res+call(pos+1, f, (sum+i)%d))%mod;
	}
	
	return dp[pos][flag][sum]=res%mod;
}

void solve(){
	string k;
	cin>>k>>d;
	
	num.clear();
	
	FOR(0, (int)k.size()-1){
		num.pb(k[i]-'0');
	}
	
	memset(dp, -1, sizeof(dp));
	
	int res=call(0,0,0);
	
	cout<<(res-1+mod)%mod<<endl;
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
