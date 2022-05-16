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
#define mod 1000000007
#define rep(i,a,b) for(int i=a; i<b; i++)
#define rrep(i,a,b) for(int i=b; i>=a; i--)
//#define endl "\n"
 
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
char dir[4]={'D','R','U','L'};
 
//****DO NOT TOUCH ABOVE THIS LINE****//
 
const int maxN=1e5+5;
struct Counter{
	int ones;
	int zeros;
	int zerosLeft;
};

void solve(){
	string s;
	cin>>s;

	int n=s.size(), cZeros=0;

	for(auto c: s){
		if(c=='0') {
			cZeros++;
		}
	}

	vector<Counter> l2r(n), r2l(n);

	rep(i,0,n){
		if(i==0){
			l2r[i].ones = s[i]-'0' == 1 ? 1 : 0;
			l2r[i].zeros = s[i]-'0' == 0 ? 1 : 0;
		}
		else{
			l2r[i].ones = (s[i]-'0' == 1 ? 1 : 0) + l2r[i-1].ones;
			l2r[i].zeros = (s[i]-'0' == 0 ? 1 : 0) + l2r[i-1].zeros;
		}
		l2r[i].zerosLeft = cZeros - l2r[i].zeros;
	}

	rrep(i,0,n-1){
		if(i==n-1){
			r2l[i].ones = s[i]-'0' == 1 ? 1 : 0;
			r2l[i].zeros = s[i]-'0' == 0 ? 1 : 0;
		}
		else{
			r2l[i].ones = (s[i]-'0' == 1 ? 1 : 0) + r2l[i+1].ones;
			r2l[i].zeros = (s[i]-'0' == 0 ? 1 : 0) + r2l[i+1].zeros;
		}
		r2l[i].zerosLeft = cZeros - r2l[i].zeros;
	}

	rep(i,0,n){
		cout<<l2r[i].ones<<" "<<l2r[i].zerosLeft<<" -- "<<r2l[n-i-1].ones<<" "<<r2l[n-i-1].zerosLeft<<"\n";
	}
	
}
 
//****DO NOT TOUCH BELOW THIS LINE****//
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	cout<<fixed<<setprecision(5);
 
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
