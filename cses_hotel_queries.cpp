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
 
const ll INF=1e18+5;
const int maxN=2e5+5;
typedef pair<int, int> pi;
 
int arr[maxN];
int st[4*maxN];
 
void build(int si, int ss, int se){
	if(ss==se){
		st[si]=arr[ss];
		return;
	}
	
	int mid=ss+(se-ss)/2;
	
	build(2*si, ss, mid);
	build(2*si+1, mid+1, se);
	
	st[si]=max(st[2*si], st[2*si+1]);
}
 
int query(int si, int ss, int se, int qs, int qe){
	if(qs>se || qe<ss) return INT_MIN;
	
	if(qs<=ss && se<=qe) return st[si];
	
	int mid=ss+(se-ss)/2;
	
	int l=query(2*si, ss, mid, qs, qe);
	int r=query(2*si+1, mid+1, se, qs, qe);
	
	return max(l,r);
}
 
void update(int si, int ss, int se, int qi){
	if(ss==se){
		st[si]=arr[ss];
		return;
	}
	
	int mid=ss+(se-ss)/2;
	
	if(qi<=mid) update(2*si, ss, mid, qi);
	else update(2*si+1, mid+1, se, qi);
	
	st[si]=max(st[2*si], st[2*si+1]);
}

void binary_find(int n, int grp, int &ans, int &index){
	int l=1, r=n;
	
	while(l<=r){
		int mid=l+(r-l)/2;
		int k=query(1, 1, n, 1, mid);
		if(k>=grp){
			r=mid-1;
			ans=k;
			index=mid;
		}
		else l=mid+1;
	}
}
 
void solve(){
	int n, m, x;
	cin>>n>>m;
	
	FOR(1, n){
		cin>>x;
		arr[i]=x;
	}
	
	build(1, 1, n);
	
	int grp;
	while(m--){
		cin>>grp;
		int ans=-1, index=-1;
		
		binary_find(n, grp, ans, index);
		
		if(ans==-1) cout<<0<<endl;
		else{
			arr[index]-=grp;
			update(1, 1, n, index);
			cout<<index<<endl;
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
