#include <bits/stdc++.h>
using namespace std;

struct node{
	int arr[3];
};

node st[400004];
int lazy[400004];

void buildtree(int si, int ss, int se){
	if(ss==se){
		st[si].arr[0]=1;
		st[si].arr[1]=0;
		st[si].arr[2]=0;
		return;
	}
	
	int mid=ss+(se-ss)/2;
	
	buildtree(2*si, ss, mid);
	buildtree(2*si+1, mid+1, se);
	
	st[si].arr[0]=st[2*si].arr[0]+st[2*si+1].arr[0];
	st[si].arr[1]=st[2*si].arr[1]+st[2*si+1].arr[1];
	st[si].arr[2]=st[2*si].arr[2]+st[2*si+1].arr[2];
}

void shift(int si){
    int k=st[si].arr[2];
	st[si].arr[2]=st[si].arr[1];
	st[si].arr[1]=st[si].arr[0];
	st[si].arr[0]=k;
}

void update(int si, int ss, int se, int qs, int qe){
	if(lazy[si]!=0){
		int dx=lazy[si];
		lazy[si]=0;
		
		if(ss!=se){
			lazy[2*si]+=dx;
			lazy[2*si+1]+=dx;
		}
		dx%=3;
		for(int i=0; i<dx; i++){
			shift(si);
		}
	}
	
	if(qe<ss || qs>se) return;
	
	if(qs<=ss && se<=qe){
		shift(si);
		if(ss!=se){
			lazy[2*si]++;
			lazy[2*si+1]++;
		}
		return;
	}
	
	int mid=ss+(se-ss)/2;
	
	update(2*si, ss, mid, qs, qe);
	update(2*si+1, mid+1, se, qs, qe);
	
	st[si].arr[0]=st[2*si].arr[0]+st[2*si+1].arr[0];
	st[si].arr[1]=st[2*si].arr[1]+st[2*si+1].arr[1];
	st[si].arr[2]=st[2*si].arr[2]+st[2*si+1].arr[2];
}

int query(int si, int ss, int se, int qs, int qe){
	if(lazy[si]!=0){
		int dx=lazy[si];
		lazy[si]=0;
		
		if(ss!=se){
			lazy[2*si]+=dx;
			lazy[2*si+1]+=dx;
		}
		dx%=3;
		for(int i=0; i<dx; i++){
			shift(si);
		}
	}
	
	if(qs>se || qe<ss) return 0;
	
	if(qs<=ss && se<=qe) return st[si].arr[0];
	
	int mid=ss+(se-ss)/2;
	int l=query(2*si, ss, mid, qs, qe);
	int r=query(2*si+1, mid+1, se, qs, qe);
	
	return l+r;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    int n, q;
	cin>>n;
	buildtree(1, 1, n);
	cin>>q;
	while(q--){
		int a,b,c;
		cin>>c>>a>>b;
		if(c==0){
			update(1, 1, n, a+1, b+1);
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
