#include <bits/stdc++.h>
using namespace std;

vector<int> arr(100001);
vector<int> st(400004), lazy(400004);

void buildtree(int si, int ss, int se){
	if(ss==se){
		st[si]=arr[ss];
		return;
	}
	
	int mid=ss+(se-ss)/2;
	
	buildtree(2*si, ss, mid);
	buildtree(2*si+1, mid+1, se);
	
	st[si]=st[2*si]+st[2*si+1];
}

void update(int si, int ss, int se, int qs, int qe, int val){
	if(lazy[si]!=0){
		int dx=lazy[si];
		lazy[si]=0;
		st[si]+=dx*(se-ss+1);
		
		if(ss!=se){
			lazy[2*si]+=dx;
			lazy[2*si+1]+=dx;
		}
	}
	
	if(qe<ss || qs>se) return;
	
	if(qs<=ss && se<=qe){
		st[si]+=(se-ss+1)*val;
		if(ss!=se){
			lazy[2*si]+=val;
			lazy[2*si+1]+=val;
		}
		return;
	}
	
	int mid=ss+(se-ss)/2;
	
	update(2*si, ss, mid, qs, qe, val);
	update(2*si+1, mid+1, se, qs, qe, val);
	
	st[si]=st[2*si]+st[2*si+1];
}

int query(int si, int ss, int se, int qs, int qe){
	if(lazy[si]!=0){
		int dx=lazy[si];
		lazy[si]=0;
		st[si]+=dx*(se-ss+1);
		
		if(ss!=se){
			lazy[2*si]+=dx;
			lazy[2*si+1]+=dx;
		}
	}
	
	if(qs>se || qe<ss) return 0;
	
	if(qs<=ss && se<=qe) return st[si];
	
	int mid=ss+(se-ss)/2;
	int l=query(2*si, ss, mid, qs, qe);
	int r=query(2*si+1, mid+1, se, qs, qe);
	
	return l+r;
}

int main() {
    int n, q;
	cin>>n;
	buildtree(1, 1, n);
	cin>>q;
	while(q--){
		int a,b,c;
		cin>>c>>a>>b;
		if(c==0){
			update(1, 1, n, a+1, b+1, 1);
		}
		else if(c==1){
			cout<<query(1, 1, n, a+1, b+1)<<endl;
		}
	}
}

/*
4 7
1 0 3
0 1 2
0 1 3
1 0 0
0 0 3
1 3 3
1 0 3
*/
