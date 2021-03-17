#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define int long long
 
signed main() {
    int n, k;
    cin>>n>>k;
    
    vector<int> arr(n+1);
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    
    vector<vector<int>> dp(n+1, vector<int> (k+1, 0));
    
    // dp[i][j] - state which represents no. ways to distribute "j" candies among children upto index "i"
    // in the input array "arr"
    
    // Transitions - To distribute "j" candies among children upto index "i", we can give:
    // 0 candy to ith child and j candies to rest i-1 children
    // 1 candy to ith child and j-1 candies to rest i-1 children
    // ....and so on.
    
    for(int i=0; i<=k; i++){
        if(i<=arr[1]) dp[1][i]=1;
        else break;
    }
    
    if(n!=1){
        for(int i=1; i<=k; i++){
            dp[1][i]=(dp[1][i]+dp[1][i-1])%mod;
        }
    }
    
    for(int i=2; i<=n; i++){
        for(int j=0; j<=k; j++){
            int a=j-arr[i];
            if(a>0) dp[i][j]=(dp[i][j]+(dp[i-1][j]-dp[i-1][a-1]+mod))%mod;
            else dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
        }
        if(i!=n){
            for(int j=1; j<=k; j++){
                dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
            }
        }
    }
    
    cout<<dp[n][k]%mod<<endl;
}
