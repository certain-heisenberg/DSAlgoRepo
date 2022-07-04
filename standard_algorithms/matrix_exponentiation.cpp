#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i=1; i<=n; i++)

typedef long long ll;
typedef vector<ll> v;
typedef vector<vector<ll>> mat;

const int mod=1e9+7;

void mult(mat &A, mat& B, int dim){
	mat temp(dim+1, v (dim+1));
	
	REP(i, dim){
		REP(j, dim){
			temp[i][j]=0;
			REP(k, dim){
				temp[i][j]=(temp[i][j]%mod + (A[i][k]%mod*B[k][j]%mod))%mod;
			}
		}
	}
	
	REP(i, dim){
		REP(j, dim)
			A[i][j]=temp[i][j];
	}
}


void power(mat &A, mat &I, int dim, int n){
	REP(i, dim){
		REP(j, dim){
			if(i==j){
				I[i][j]=1;
			}
			else{
				I[i][j]=0;
			}
		}
	}
	
	//REP(i, n){
		//mult(I, A, dim);
	//}
	
	while(n){
		if(n%2)
			mult(I, A, dim), n--;
		else
			mult(A, A, dim), n/=2;
	}
	
	REP(i, dim){
		REP(j, dim){
			A[i][j]=I[i][j];
		}
	}
}

void printmat(mat &A, int dim){
	REP(i, dim){
		REP(j, dim){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}

signed main(){
	int T;
	cin>>T;
	while(T--){
		int dim, n;
		cin>>dim>>n;
		
		mat arr(dim+1, v (dim+1));
		mat I(dim+1, v (dim+1));
		
		REP(i, dim){
			REP(j, dim){
				cin>>arr[i][j];
			}
		}
		
		power(arr, I, dim, n);
		
		printmat(arr, dim);
	}
}
