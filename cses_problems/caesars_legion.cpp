#include<bits/stdc++.h>
#define mod 100000000
#define REP(i,n) for(int i=0; i<=n; i++)
using namespace std;


int f, h;
long long dp[101][101][11][11];

int getAns(int n1, int n2, int k1, int k2){
	if(n1+n2==0) return 1;
	
	if(dp[n1][n2][k1][k2]!=-1) return dp[n1][n2][k1][k2];
	//fill f
	int x=0;
	if(n1>0 && k1>0) x=getAns(n1-1, n2, k1-1, h);
	
	//fill h
	int y=0;
	if(n2>0 && k2>0) y=getAns(n1, n2-1, f, k2-1);
	
	dp[n1][n2][k1][k2]=(x+y)%mod;
	return dp[n1][n2][k1][k2];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	T=1;
	while(T--){
		int n1, n2;
		cin>>n1>>n2>>f>>h;
		
		REP(i, n1)
			REP(j, n2)
				REP(k, f)
					REP(l, h)
						dp[i][j][k][l]=-1;
		
		cout<<getAns(n1, n2, f, h)<<endl;
	}
}

/*
2 1 1 10
*/
