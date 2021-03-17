#include <bits/stdc++.h>
using namespace std;

//#define kk
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
const int maxN=2e5+5;
typedef pair<int, int> pi;

void solve(){
	int n;
	cin>>n;
	
	map<int, int> dp;
	vector<vector<int>> jobs;
	
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin>>a>>b>>c;
		jobs.push_back(vector<int>{a, b, c});
	}
	sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b) {
		return a[0] > b[0];
	});
	
	int maxT = 0;
	for (auto job : jobs) {
		auto it = dp.upper_bound(job[1]);
		int pre = (it == dp.end()) ? 0 : it->second;
		maxT = max(maxT, job[2] + pre);
		dp[job[0]] = maxT;
	}
	
	cout<<maxT<<endl;
}

void dummy_solve(){
	int n;
	cin>>n;
	
	map<int, int> dp;
	vector<vector<int>> jobs;
	
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin>>a>>b>>c;
		jobs.push_back(vector<int>{a, b, c});
	}
	sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b) {
		return a[1] < b[1];
	});
	
	dp[0]=0;
	
	for (auto job : jobs) {
		auto it = dp.lower_bound(job[0]);
		it=prev(it);
		int pre = it->second+job[2];
		if(pre>dp.rbegin()->second) dp[job[1]]=pre;
	}
		
	cout<<dp.rbegin()->second<<endl;
}

void solve1(){
	int n;
	cin>>n;
	
	map<int, int> compress;
	vector<int> a(n), b(n), p(n);
	
	for(int i=0; i<n; i++){
		cin>>a[i]>>b[i]>>p[i];
		b[i]++;
		compress[a[i]]++;
		compress[b[i]]++;
	}
	
	int coords = 0;
	for(auto &v: compress){
		v.second=coords++;
	}
	
	vector<vector<pi>> project(coords);

	for(int i=0; i<n; i++){
		project[compress[b[i]]].pb({compress[a[i]], p[i]});
	}
	
	vector<int> dp(coords, 0);
	
	for(int i=0; i<coords; i++){
		if(i>0) dp[i]=dp[i-1];
		
		for(pi c: project[i]){
			dp[i]=max(dp[i], dp[c.first]+c.second);
		}
	}
	
	cout<<dp[coords-1]<<endl;
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
		solve1();
	}
}

