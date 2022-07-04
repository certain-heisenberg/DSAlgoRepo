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
typedef pair<int, int> pi;

//****DO NOT TOUCH ABOVE THIS LINE****//

const int maxN=1e4+5;

void solve(){
	int total, k;
	cin>>total>>k;
	
    vector<vector<int>> dp(k+1, vector<int> (total+1 , 0));
    
    dp[0][0]=1;
    for(int i=1; i<=k; i++){
		dp[i][0]=1;
	}
    
    for(int i=1; i<=k; i++){
        for(int j=1; j<=total; j++){
            if(i<=j) dp[i][j]=dp[i-1][j]+dp[i][j-i];
            else dp[i][j]=dp[i-1][j];
        }
    }
    
    
    for(int i=0; i<=k; i++){
        for(int j=0; j<=total; j++){
			cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[k][total]<<endl;
	
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
