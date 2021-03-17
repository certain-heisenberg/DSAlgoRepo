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

vector<int> arr[maxN];
int dp[maxN][2];
int m;

void getAns(int v, int p){
	dp[v][0]=dp[v][1]=1;
	
	for(int child: arr[v]){
		if(child!=p){
			getAns(child, v);
			dp[v][0]=(dp[v][0]%m*(dp[child][0]+dp[child][1])%m)%m;
			dp[v][1]=(dp[v][1]%m*dp[child][1]%m)%m;
		}
	}
}

void eval_Ans(int v, int p, int b_par_ans, int w_par_ans){
	vector<int> b_pref, b_suf;
	vector<int> w_pref, w_suf;
	
	for(int child: arr[v]){
		if(child!=p){
			b_pref.pb(dp[child][0]+dp[child][1]);
			b_suf.pb(dp[child][0]+dp[child][1]);
			w_pref.pb(dp[child][1]);
			w_suf.pb(dp[child][1]);
		}
	}
	
	int n=b_pref.size();
	
	for(int i=1; i<n; i++){
		b_pref[i]=(b_pref[i]%m*b_pref[i-1]%m)%m;
		b_suf[n-i-1]=(b_suf[n-i-1]%m*b_suf[n-i]%m)%m;
		w_pref[i]=(w_pref[i]%m*w_pref[i-1]%m)%m;
		w_suf[n-i-1]=(w_suf[n-i-1]%m*w_suf[n-i]%m)%m;
	}
	
	int c_no=0;
	for(int child: arr[v]){
		if(child!=p){
			int b_left_ans = (c_no==0) ? 1 : b_pref[c_no-1];
			int b_right_ans = (c_no==n-1) ? 1 : b_suf[c_no+1];
			
			int w_left_ans = (c_no==0) ? 1 : w_pref[c_no-1];
			int w_right_ans = (c_no==n-1) ? 1 : w_suf[c_no+1];
			
			int b_cur_par_ans=(w_par_ans+(b_left_ans%m*b_right_ans%m*b_par_ans%m)%m)%m;	
			int w_cur_par_ans=(w_left_ans%m*w_right_ans%m*w_par_ans%m)%m;
			
			eval_Ans(child, v, b_cur_par_ans, w_cur_par_ans);
			c_no++;
		}
	}
	
	int b_temp=(n==0) ? 1 : b_pref[n-1];
	int w_temp=(n==0) ? 1 : w_pref[n-1];
	
	dp[v][0]=(b_temp%m*b_par_ans%m)%m;
	dp[v][1]=(w_temp%m*w_par_ans%m)%m;
}

void solve(){
	int n;
	cin>>n>>m;
	
	FOR(1, n-1){
		int a, b;
		cin>>a>>b;
		arr[a].pb(b);
		arr[b].pb(a);
	}
	
	getAns(1, -1);
	
	eval_Ans(1, -1, 1, 1);
	
	FOR(1, n){
		cout<<dp[i][0]%m<<endl;
	}
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
