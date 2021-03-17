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
const int maxN=1e5+5;
typedef pair<int, int> pi;

int flag[maxN];

void solve(){
	int n, l;
	cin>>n>>l;
	
	FOR(1, n) cin>>flag[i];
	
	double t=0;
	
	int s=1;
	int e=n;
	
	double v1=1;
	double v2=1;
	
	double x=0;
	double y=l;
	
	while(s<=e){
		double a=flag[s]-x;
		double b=y-flag[e];
		
		double t1=a/v1;
		double t2=b/v2;
		
		if(t1>t2){
			t+=t2;
			x+=(v1*b)/v2;
			y-=b;
			v2++;
			e--;
		}
		else if(t1<t2){
			t+=t1;
			x+=a;
			y-=(v2*a)/v1;
			v1++;
			s++;
		}
		else{
			t+=t1;
			x+=a;
			y-=b;		
			v1++;
			v2++;
			s++;
			e--;
		}
	}
	
	t+=(y-x)/(v1+v2);
	cout<<t<<endl;
}
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cout<<fixed<<setprecision(15);
	
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

