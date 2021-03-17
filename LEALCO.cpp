#include <bits/stdc++.h>
using namespace std;
 
#define kk
//#define int long long
#define FOR(a, b) for(int i=a; i<=b; i++)
#define REP(i, a, b) for(int i=a; i<=b; i++)
#define ff first
#define ss second
#define ll long long
#define inf 1000000000
#define pb push_back
#define mod 1000000007
 
const ll INF=1e18+5;
const int maxN=2e5+5;
typedef pair<int, int> pi;


int n,k,m;

int isBad(vector<int> &R){
	for(int i=0; i<=n-k; i++){
		
		int maxR=0, cnt=0;

		for(int j=i; j<i+k; j++){
			if(maxR==R[j]){
				cnt++;
			}else if(maxR<R[j]){
				maxR=R[j];
				cnt=1;
			}
		}

		if (cnt>=m) {
			return true;
		}
	}
	return false;
}

void bitmask(vector<int> &arr){
	int res=n+1;
	
	for(int mask=0; mask<(1<<n); mask++){
		int size=__builtin_popcount(mask);
		
		if(size<res){
			vector<int> new_arr(n);
			
			for(int i=0; i<n; i++){
				if(mask & (1<<i)) new_arr[i]=arr[i]+1;
				else new_arr[i]=arr[i];
			}
			
			if(!isBad(new_arr)){
				res=size;
			}
		}
	}
	
	if(res==n+1) res=-1;
	
	cout<<res<<endl;
}


void solve(){
	cin>>n>>k>>m;
	
	vector<int> arr(n);
	FOR(1, n) cin>>arr[i-1];
	
	bitmask(arr);
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
		solve();
	}
}
