#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> primes;

void sieve(){
	int maxN=100000;
	vector<bool> arr(maxN+1, false);
	
	arr[0]=true;
	arr[1]=true;
	for(ll i=2; i<=maxN; i++){
		if(!arr[i]){
			for(ll j=i*i; j<=maxN; j+=i){
				arr[j]=true;
			}
		}
	}
	
	for(int i=0; i<=maxN; i++){
		if(!arr[i]) primes.push_back(i);
	}
}

void init(int l, int r){
	if(l==1) l++;
	
	int N=r-l+1;
	vector<bool> arr(N, false);
	
	for(ll p: primes){
		if(p*p<=r){
			int k=(l/p)*p;
			if(k<l) k+=p;
			
			for(; k<=r; k+=p){
				if(k!=p){
					arr[k-l]=true;
				}
			}
		}
	}
	
	for(int i=0; i<N; i++){
		if(!arr[i]){
			cout<<l+i<<endl;
		}
	}
}

int main(){	
	sieve();
	int T;
	cin>>T;
	while(T--){
		int l, r;
		cin>>l>>r;
		init(l, r);
		cout<<endl;
	}
}
