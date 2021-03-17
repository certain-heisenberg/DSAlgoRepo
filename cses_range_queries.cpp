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

int arr[maxN];
int st[4*maxN];
int lazy[4*maxN];

void build(int si, int ss, int se){
	if(ss==se){
		st[si]=arr[ss];
		return;
	}
	
	int mid=ss+(se-ss)/2;
	
	build(2*si, ss, mid);
	build(2*si+1, mid+1, se);
	
	st[si]=st[2*si]+st[2*si+1];
}

int query(int si, int ss, int se, int qs, int qe){
	if(lazy[si]!=0){
		int dx=lazy[si];
		lazy[si]=0;
		st[si]+=dx*(se-ss+1);
		if(ss!=se){
			lazy[2*si]+=dx;
			lazy[2*si+1]+=dx;
		}
	}
	
	if(qs>se || qe<ss) return 0;
	
	if(qs<=ss && se<=qe) return st[si];
	
	int mid=ss+(se-ss)/2;
	
	int l=query(2*si, ss, mid, qs, qe);
	int r=query(2*si+1, mid+1, se, qs, qe);
	
	return l+r;
}

void update(int si, int ss, int se, int qs, int qe, int val){
	if(lazy[si]!=0){
		int dx=lazy[si];
		lazy[si]=0;
		st[si]+=dx*(se-ss+1);
		if(ss!=se){
			lazy[2*si]+=dx;
			lazy[2*si+1]+=dx;
		}
	}
	
	if(ss>qe || se<qs) return;
	
	if(ss>=qs && se<=qe){
		int dx=(se-ss+1)*val;
		st[si]+=dx;
		if(ss!=se){
			lazy[2*si]+=val;
			lazy[2*si+1]+=val;
		}
		return;
	}
	
	int mid=ss+(se-ss)/2;
	
	update(2*si, ss, mid, qs, qe, val);
	update(2*si+1, mid+1, se, qs, qe, val);
	
	st[si]=st[2*si]+st[2*si+1];
}

void solve(){
	int n, q, x;
	cin>>n>>q;
	
	FOR(1, n){
		cin>>x;
		arr[i]=x;
	}
	
	build(1, 1, n);
	
	int c;
	while(q--){
		cin>>c;
		if(c==1){
			int a, b, u;
			cin>>a>>b>>u;
			update(1, 1, n, a, b, u);
		}
		else{
			int k;
			cin>>k;
			cout<<query(1, 1, n, k, k)<<endl;
		}
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

