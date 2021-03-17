#include<bits/stdc++.h>
#define ll long long

using namespace std;

//void getnck(int n, int k, vector<vector<ll>> &nck){
	//for(int i=0; i<=n; i++){
		//nck[i][0]=1;
	//}
	//for(int i=1; i<=k; i++){
		//nck[0][i]=0;
	//}
	
	//for(int i=1; i<=n; i++){
		//for(int j=1; j<=k; j++){
			//nck[i][j]=nck[i-1][j]+nck[i-1][j-1];
		//}
	//}
//}

ll nck(int n, int k){
	
	ll res=1;
	
	for(int i=0; i<k; i++){
		res*=(n-i), res/=(i+1);
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	while(T--){
		int n, k;
		cin>>n>>k;
		
		n--, k--;
		k=min(k, n-k);
		cout<<nck(n, k)<<endl;
		//vector<vector<ll>> nck(n+1, vector<ll>(k+1));
		//getnck(n, k, nck);
		
		//cout<<nck[n][k]<<endl;
	}
}
