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
//#define endl "\n"

const ll INF=1e18+5;

const int naxN=2e1+5;
int fact[naxN], inv_fact[naxN];

int power(int a, int n){
	int res=1;
	
	while(n){
		if(n%2) res=(res*a)%mod, n--;
		else a=(a*a)%mod, n/=2;
	}
	return res%mod;
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
//int dy[8]={-1, 0, 1, 1, 1, 0, -1, -1};

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

//****DO NOT TOUCH ABOVE THIS LINE****//

const int maxN=2e5+5;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

vector<string> v;
vector<vector<bool>> vis;

int n,m;

bool isValid(int a, int b){
	if(a<0 || a>=n || b<0 || b>=m) return false;
	return true;
}

bool isBlackAround(int x, int y){
	int W=0, B=0;
	
	for(int i=0; i<4; i++){
		int a=x+dx[i];
		int b=y+dy[i];
		if(isValid(a, b)){
			if(v[a][b]=='W') W=1;
			if(v[a][b]=='B') B=1;
		}
	}
	
	if(B && W) return false;
	
	if(B) return true;
	return false;
}

bool isWhiteAround(int x, int y){
	int W=0, B=0;
	
	for(int i=0; i<4; i++){
		int a=x+dx[i];
		int b=y+dy[i];
		if(isValid(a, b)){
			if(v[a][b]=='W') W=1;
			if(v[a][b]=='B') B=1;
		}
	}
	
	if(B && W) return false;
	
	if(W) return true;
	return false;
}

void dfs(int x, int y, int cnt, int N){
	if(cnt==N) return;
	
	for(int i=0; i<4; i++){
		int a=x+dx[i];
		int b=y+dy[i];

		if(isValid(a, b) && !vis[a][b]){
			if(v[a][b]=='-'){
				vis[a][b]=1;
				dfs(a, b, cnt, N);
				//vis[a][b]=0;
			}
			else if(isBlackAround(a, b)){
				v[a][b]='W';
				vis[a][b]=1;
				dfs(a, b, cnt+1 ,N);
				//v[a][b]='.';
				//vis[a][b]=0;
			}
			else if(isWhiteAround(a, b)){
				v[a][b]='B';
				vis[a][b]=1;
				dfs(a, b, cnt+1, N);
				//v[a][b]='.';
				//vis[a][b]=0;
			}
		}
	}
}

void solve(){
	cin>>n>>m;
	
	cin.ignore();
	
	v.resize(n);
	vis.resize(n, vector<bool> (m, 0));
	
	int N=0;
	
	for(int i=0; i<n; i++){
		cin>>v[i];
		for(auto c: v[i]) if(c=='.') N++;
	}	
	
	if(v[0][0]=='.') v[0][0]='B';
	
	dfs(0,0,0,N);
	
	for(auto c: v) cout<<c<<endl;
}

//****DO NOT TOUCH BELOW THIS LINE****//

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cout<<fixed<<setprecision(18);

	#ifdef kk
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	//preprocess();
		
	int T=1;
	//cin>>T;

	while(T--){
		solve();
	}
}
