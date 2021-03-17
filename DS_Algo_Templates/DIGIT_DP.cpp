#include <bits/stdc++.h>
using namespace std;

vector<int> num;
long long dp[11][2][100];

long long call(int pos, int flag, long long sum){
	
	if(pos==(int)num.size()) return sum;
	
	if(dp[pos][flag][sum]!=-1) return dp[pos][flag][sum];
	long long res=0;
	
	int limit;
	if(flag==0) limit=num[pos];
	else limit=9;
	
	for(int i=0; i<=limit; i++){
		int f=flag;
		if(i<limit) f=1;
		res+=call(pos+1, f, sum+i);
	}
	
	return dp[pos][flag][sum]=res;
}

long long solve(int n){
	num.clear();
	
	while(n){
		num.push_back(n%10);
		n/=10;
	}
	
	reverse(num.begin(), num.end());
	memset(dp, -1, sizeof(dp));
	long long res=call(0,0,0);
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	//int T;
	//cin>>T;
	while(1){
		int n,m;
		cin>>n>>m;
		
		if(n==-1) break;
		
		long long res=solve(m)-solve(n-1);
		
		cout<<res<<endl;
	}
}
/*

 */
