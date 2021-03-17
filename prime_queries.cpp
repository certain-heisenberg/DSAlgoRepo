#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>

using namespace std;

map<ll, ll> primes;
ll total;

void factorise(ll n){
	total=1;
	for(ll i=2; i*i<=n; i++){
		if(n%i==0){
			ll cnt=0;
			while(n%i==0){
				cnt++;
				n/=i;
			}
			total*=(cnt+1);
			primes[i]=cnt;
		}
	}
	
	if(n>1) primes[n]=1, total*=2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll n, q;
	cin>>n>>q;
	primes.clear();
	factorise(n);
	
	while(q--){
		ll t, k;
		cin>>t>>k;
		if(t==1){
			ll res=1;
	
			for(pll i: primes){
				ll x=i.first;
				ll cnt=0;
				while(k%x==0){
					cnt++;
					k/=x;
				}
				res*=(min(cnt, i.second)+1);
			}
			cout<<res<<endl;
		}
		else{
			ll res=1;
	
			for(pll i: primes){
				ll x=i.first;
				ll cnt=0;
				while(k%x==0){
					cnt++;
					k/=x;
				}
				
				if(cnt>i.second){
					res=0;
					break;
				}
				res*=(i.second-cnt+1);
			}
			
			if(k>1) res=0;
			if(t==2) cout<<res<<endl;
			else if(t==3) cout<<total-res<<endl;
		}
	}
}
