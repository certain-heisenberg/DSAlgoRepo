#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAXN 100009
array<pair<long long , long long>, MAXN>arr;
long long ans[MAXN];

signed main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
    #endif
    
    int n , k , p ; scanf("%d%d%d",&n,&k,&p);
    for(int i=0;i<n;++i){
        arr[i].second = i;
        scanf("%lld",&arr[i].first);
    }
    sort(arr.begin(),arr.begin()+n); 
    for(int i=0;i<n;++i){
        // just need to check to what distance current frog can send message 
        ans[arr[i].second] = i;
        int j = i+1;
        while(j<n && arr[j-1].first+k>=arr[j].first){
            ans[arr[j].second] = i;
            ++j;
        }
        i=--j;
    }
    for(int i=0;i<p;++i){
        int a,b;scanf("%d%d",&a,&b);--a;--b;
        puts((ans[a]==ans[b])?"Yes":"No");
    }
    return 0;
}
