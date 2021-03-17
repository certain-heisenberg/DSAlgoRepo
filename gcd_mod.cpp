#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define mod 1000000007

ll power(ll a, ll n, ll d){
	ll res=1;
	
	while(n){
		if(n%2)
			res=((res%d)*(a%d))%d, n--;
		else
			res=((a%d)*(a%d))%d, n/=2;
	}
	return res;
}

ll gcd(ll a, ll b, ll n){
	if(a==b){
		return (power(a, n, mod)+power(b, n, mod))%mod;
	}
	
	ll dif=a-b;
	ll candidate=1;
	
	for(ll i=1; i*i<=dif; i++){
		if(dif%i==0){
			ll temp=(power(a, n, i)+power(b, n, i))%i;
			if(temp==0) candidate=max(candidate, i);
			
			temp=(power(a, n, dif/i)+power(b, n, dif/i))%(dif/i);
			if(temp==0) candidate=max(candidate, dif/i);
		}
	}
	return candidate%mod;
}

int main(){	
	ll T;
	cin>>T;
	while(T--){
		ll a, b, n;
		cin>>a>>b>>n;
		cout<<gcd(a, b, n)<<endl;
	}
}
