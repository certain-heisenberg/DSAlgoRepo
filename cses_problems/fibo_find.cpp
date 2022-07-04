#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)

typedef long long ll;
typedef vector<ll> v;
typedef vector<vector<ll>> mat;

const int mod=1e9+7;

void mult(mat &A, mat &B){
	mat temp(2, v (2));
	
	REP(i, 2){
		REP(j, 2){
			temp[i][j]=0;
			REP(k, 2){
				temp[i][j]=(temp[i][j]%mod + (A[i][k]%mod*B[k][j]%mod))%mod;
			}
		}
	}
	
	REP(i, 2){
		REP(j, 2)
			A[i][j]=temp[i][j];
	}
}


void power(mat &X, mat &A, mat &I, int n){
	while(n){
		if(n%2)
			mult(I, A), n--;
		else
			mult(A, A), n/=2;
	}
	
	REP(i, 2){
		REP(j, 2){
			A[i][j]=I[i][j];
		}
	}
	
	mat temp(1, v (2));
	
	REP(i, 1){
		REP(j, 2){
			temp[i][j]=0;
			REP(k, 2){
				temp[i][j]=(temp[i][j]%mod + (X[i][k]%mod*A[k][j]%mod))%mod;
			}
		}
	}
	
	REP(i, 1){
		REP(j, 2)
			X[i][j]=temp[i][j];
	}
	
}

signed main(){
	int T;
	cin>>T;
	while(T--){
		int f0, f1, n;
		cin>>f0>>f1>>n;
		
		mat   X={{f0, f1}};
		
		mat arr={{0,1},
			     {1, 1}};
		mat   I={{1,0},
			     {0,1}};
		
		power(X, arr, I, n-1);
		
		cout<<X[0][1]<<endl;
	}
}

/*
8  
2 3 1  
9 1 7  
9 8 3  
2 4 9  
1 7 2  
1 8 1  
4 3 1  
3 7 5  
*/


