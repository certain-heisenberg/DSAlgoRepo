#include <bits/stdc++.h>
using namespace std;

//#define kk
#define int long long
#define endl "\n"

const int maxN=2e4+5;

int n;

//**** Using Fewnick Tree ****//
//int ft[maxN]; // ft - Fenwick Tree or Binary Indexed Tree

//void update(int i, int val){
	//while(i<=n){
		//ft[i]+=val;
		//i+=i & (-i);
	//}
//}

//int query(int i){
	//int sum=0;
	
	//while(i>0){
		//sum+=ft[i];
		//i-=i & (-i);
	//}
	//return sum;
//}

//void build(){
	//for(int i=1; i<=n; i++){
		//update(i, 1);
	//}
//}

//**** Using Segment Tree ****//
int arr[maxN];
int st[4*maxN]; // st - Segment Tree

void build(int si, int ss, int se){
	if(ss==se){
		st[si]=arr[ss];
		return;
	}
	
	int mid=ss+(se-ss)/2;
	
	build(2*si, ss, mid);
	build(2*si+1, mid+1, se);
	
	st[si]=st[2*si]+st[2*si+1];
}

int query(int si, int ss, int se, int qs, int qe){
	if(qe<ss || qs>se) return 0;
	
	if(qs<=ss && se<=qe) return st[si];
	
	int mid=ss+(se-ss)/2;
	
	int l=query(2*si, ss, mid, qs, qe);
	int r=query(2*si+1, mid+1, se, qs, qe);
	
	return l+r;
}

void update(int si, int ss, int se, int qi){
	if(ss==se){
		st[si]=arr[ss];
		return;
	}
	
	int mid=ss+(se-ss)/2;
	
	if(qi<=mid) update(2*si, ss, mid, qi);
	else update(2*si+1, mid+1, se, qi);
	
	st[si]=st[2*si]+st[2*si+1];
}

void solve(){
	cin>>n;
	
	vector<int> v(n);
	
	int k=1;
	int s=1, e=n;
	
	//**** Using Fewnick Tree ****//
	//build();
	
	//while(k<=n){		
		//s=(s+k)%e;
		//if(s==0) s=e;
		//e--;
		
		//int l=1, r=n, mid;
		//while(l<r){
			//mid=l+(r-l)/2;
		
			//if(query(mid)>=s) r=mid;
			//else l=mid+1;
		//}
		
		//update(r, -1);
		//v[r-1]=k;
		//k++;
	//}
	
	//**** Using Segment Tree ****//
	for(int i=1; i<=n; i++) arr[i]=1;
	
	build(1, 1, n);
	
	while(k<=n){       
		s=(s+k)%e;
		if(s==0) s=e;
		e--;
		
		int l=1, r=n, mid;
		while(l<r){
			mid=l+(r-l)/2;
		
			if(query(1, 1, n, l, mid)>=s) r=mid;
			else l=mid+1;
		}
	
		arr[r]=0;
		update(1, 1, n, r);
		v[r-1]=k;
		k++;
	}
	
	for(int c: v) cout<<c<<" ";
	cout<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cout<<fixed<<setprecision(6);
	
	#ifdef kk
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int T;
	cin>>T;
	
	while(T--){
		solve();
	}
}
