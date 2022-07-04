// Input: 
// 1
// 4 3
// 1 2 3
// 2 3 1
// 2 4 7
// 3 6 2 2
// 1 4

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
#define endl "\n"

const ll INF=1e18+5;
const int maxN=1e6+5;
typedef pair<int, int> pi;

int dist[305][305];
int f_rate[305];
int dp[305];

//Method - 1
pi f[305];

void solve(){
	int n, R, u, v, w;
	cin>>n>>R;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i==j) dist[i][j]=0;
			else dist[i][j]=INF;
		}
	}
	
	for(int i=1; i<=R; i++){
		cin>>u>>v>>w;
		dist[u][v]=min(dist[u][v], w);
		dist[v][u]=min(dist[v][u], w);
	}
	
	// APSP - Floyd Warshall Algo
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}
	
	for(int i=1; i<=n; i++){
		int x;
		cin>>x;
		f_rate[i]=x;
		f[i].ff=x;
		f[i].ss=i;
	}
	
	sort(f+1, f+n+1, [&](pi a, pi b){
		return a.ff>b.ff;
	});
	
	int P, Q;
	cin>>P>>Q;
	
	int ans=INF;
	
	for(int i=1; i<=n; i++){		
		// dp[i] - min cost to travel from state "P" to state "i" with tank getting filled at 
		//         state "P" only
		dp[i]=dist[P][f[i].ss]*f_rate[P];
		
		for(int j=1; j<i; j++){
			dp[i]=min(dp[i], dp[j]+dist[f[j].ss][f[i].ss]*f[j].ff);
		}
		ans=min(ans, dp[i]+dist[f[i].ss][Q]*f[i].ff);
	}
	
	cout<<ans<<endl;
}

// Method - 2
void solve1(){
	int n, R, u, v, w;
	cin>>n>>R;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i==j) dist[i][j]=0;
			else dist[i][j]=INF;
		}
	}
	
	for(int i=1; i<=R; i++){
		cin>>u>>v>>w;
		dist[u][v]=min(dist[u][v], w);
		dist[v][u]=min(dist[v][u], w);
	}
	
	// APSP - Floyd Warshall Algo
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}
	
	for(int i=1; i<=n; i++){
		int x;
		cin>>x;
		f_rate[i]=x;
	}
	
	int P, Q;
	cin>>P>>Q;
	
	for(int i=1; i<=n; i++){
		dp[i]=INF;
	}
	
	dp[P]=0;
	
	// dp[i] - min cost to travel from state "P" to state "i" with tank getting filled at 
	//         state "P" only
	
	for(int k=1; k<=n; k++){		
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				dp[i]=min(dp[i], dp[j]+dist[j][i]*f_rate[j]);
			}
		}
	}
	
	cout<<dp[Q]<<endl;
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
		solve1();
	}
}

