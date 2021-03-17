#include<bits/stdc++.h>
#define mod 1000000007

typedef long long ll;

using namespace std;

void mul(ll I[][2], ll A[][2]){
	ll temp[2][2];
		
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			temp[i][j]=0;
			for(int k=0; k<2; k++){
				temp[i][j]+=(I[i][k]*A[k][j])%mod;
			}
		}
	}
		
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			I[i][j]=temp[i][j];
		}
	}
}

void power(ll A[][2], ll n){
	ll I[2][2]={{1, 0},
		        {0, 1}};
		        
	while(n){
		if(n%2) mul(I, A), n--;
		else mul(A, A), n/=2;
	}
	
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			A[i][j]=I[i][j];
		}
	}	
}

void prod(ll res[][2], ll A[][2], ll n){
		power(A, n-1);
		ll temp[1][2];
		
		for(int i=0; i<1; i++){
			for(int j=0; j<2; j++){
				temp[i][j]=0;
				for(int k=0; k<2; k++){
					temp[i][j]+=res[i][k]*A[k][j];
				}
			}
		}
		
		for(int i=0; i<1; i++){
			for(int j=0; j<2; j++){
				res[i][j]=temp[i][j];
			}
		}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	while(T--){
		ll n;
		cin>>n;
		ll res[1][2]={{1, 2}};
		
		ll A[2][2]={{0, 1},
			         {1, 1}};
			         
		prod(res, A, n);
	    cout<<res[0][0]%mod<<endl;
	}
}
