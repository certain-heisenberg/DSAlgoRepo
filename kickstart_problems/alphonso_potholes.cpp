#include <bits/stdc++.h>
using namespace std;
 
#define kk
//#define int long long
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
#define endl "\n"
 
const ll INF=1e18+5;
typedef pair<int, int> pi;

//****DO NOT TOUCH ABOVE THIS LINE****//

const int maxN=1e4+5; // max grid size

bool arr[maxN][maxN];
bool vis[maxN][maxN];

map<int, pi> mp;

int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};

int n, m, ans;

bool isValid(int x, int y){
	if(x<1 || x>n || y<1 || y>m || arr[x][y]) return false;
	return true;
}

void dfs(int x, int y, int tim, int ox, int oy){
	if(x==ox && y==oy){
		ans=min(ans, tim);
		return;
	}
	
	int c=mp[tim].first;
	int d=mp[tim].second;
	arr[c][d]=1;
	
	vis[x][y]=1;
	
	for(int i=0; i<4; i++){
		int p=x+dx[i];
		int q=y+dy[i];
		if(isValid(p, q) && vis[p][q]){
			dfs(p, q, tim+1, ox, oy);
		}
	}
}

void solve(){
	int ox, oy, p;
	cin>>n>>m>>ox>>oy>>p;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>arr[i][j];
		}
	}
	
	mp.clear();
	for(int i=1; i<=p; i++){
		int c, d, e;
		cin>>c>>d>>e;
		mp[e]={c, d};
	}
	
	ans=INT_MAX;
	dfs(1, 1, 0, ox, oy);
	
	if(ans==INT_MAX) cout<<"Work From Home"<<endl;
	else cout<<ans<<endl;
}

//****DO NOT TOUCH BELOW THIS LINE****//

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
