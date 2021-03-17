#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000000000

int n;
pair<int, int> arr[3001];
long long dp[3001][3001];

long long getAns(int pos, int pre){
	if(pos>n) return 0;
	
	if(dp[pos][pre]!=inf) return dp[pos][pre];
	
	//pin it
	long long x=arr[pos].second+getAns(pos+1, pos);
	
	//leave it
	long long y=abs(arr[pre].first-arr[pos].first)+getAns(pos+1, pre);
	
	return dp[pos][pre]=min(x,y);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	
	for(int i=1; i<=n; i++){
		cin>>arr[i].first>>arr[i].second;
	}
	
	sort(arr+1, arr+n+1);
	
	for(int i=0; i<=3000; i++){
		for(int j=0; j<=3000; j++){
			dp[i][j]=inf;
		}
	}
	
	long long ans=getAns(2, 1)+arr[1].second;
	
	cout<<ans;
}

/*
3
2 3
3 4
1 2
*/
