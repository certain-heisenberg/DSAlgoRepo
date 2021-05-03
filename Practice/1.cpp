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
#define kk

const int maxN=1e5+5;

void solve(){
	int n;
	cin>>n;
	
	vector<int> u(n), s(n);
	
	rep(i,0,n) cin>>u[i];
	
	rep(i,0,n) cin>>s[i];
	
	map<int, multiset<int, greater<int>>> Tmp;
	map<int, vi> mp;
	
	rep(i,0,n) Tmp[u[i]].insert(s[i]);
	
	for(auto p: Tmp){
		vi v;
		for(auto c: p.ss) v.pb(c);
		
		for(int i=1; i<(int)v.size(); i++) v[i]+=v[i-1];
		mp[p.ff]=v;
	}
	
	int k=1;
	
	while(1){
		int f=0;
		int ans=0;
		
		for(auto p: mp){
			int x=p.ss.size()/k;
			if(x>0){
				f=1;
				ans+=p.ss[p.ss.size()-1];

				if(x*k-1>=0) ans-=p.ss[p.ss.size()-1]-p.ss[x*k-1];
				else ans-=p.ss[p.ss.size()-1];
			}
		}
		
		
		if(f==0) break;
		cout<<ans<<" ";
		k++;
	}
	
	for(int i=k-1; i<n; i++) cout<<0<<" ";
	
	cout<<endl;
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
