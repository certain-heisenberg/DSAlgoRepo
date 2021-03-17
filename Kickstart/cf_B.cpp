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

int points;

void backtrack(string s, int k, int i, int score){
    points=max(points, score);
    if(i==(int)s.size()) return;
    
    if(s[i]=='L'){
        backtrack(s, k, i+1, score);
        if(k>0){
            if(i>0 && s[i-1]=='W'){
                s[i]='W';
                backtrack(s, k-1, i+1, score+2);
                s[i]='L';
            }
            else{
                s[i]='W';
                backtrack(s, k-1, i+1, score+1);
                s[i]='L';
            }
        }
    }
    else{
        if(i>0 && s[i-1]=='W') backtrack(s, k, i+1, score+2);
        else backtrack(s, k, i+1, score+1);
    }
}

void solve(){
	int n, k;
	cin>>n>>k;
	
	string s;
	cin>>s;

	points=INT_MIN;
	backtrack(s, k, 0, 0);
	cout<<points<<endl;
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

