#include <bits/stdc++.h>
using namespace std;

bool arr[1000001];
int pp[1000001];

void sieve(){
	int maxN=1000000;
	arr[0]=true;
	arr[1]=true;
	
	for(int i=2; i*i<=maxN; i++){
		if(!arr[i]){
			for(int j=i*i; j<=maxN; j+=i){
				arr[j]=true;
			}
		}
	}
	
	int cnt=0;
	for(int i=0; i<=maxN; i++){
		if(!arr[i]) cnt++;
		if(!arr[cnt]) pp[i]=1;
		else pp[i]=0;
	}
	
	for(int i=0; i<=maxN; i++){
		pp[i]+=pp[i-1];
	}
}


int main(){
	sieve();
	int q;
	cin>>q;
	while(q--){
		int l, r;
		cin>>l>>r;
		cout<<pp[r]-pp[l-1]<<endl;
	}
}
/*
7
1
10
100
1000
10000
100000
1000000
 */
