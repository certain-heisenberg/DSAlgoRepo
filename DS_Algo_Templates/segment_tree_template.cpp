#include <bits/stdc++.h>
using namespace std;

const int maxN=1e5+5;
 
int arr[maxN];
int st[4*maxN];
int lazy[4*maxN];

void build(int si, int ss, int se){
	if(ss==se){
		st[si]=arr[ss];
		return;
	}
	
	int mid=ss+(se-ss)/2;
	
	build(2*si, ss, mid);
	build(2*si+1, mid+1, se);
	
	st[si]=st[2*si]+st[2*si+1]; //Needs to be changed 
}

//**** For range query and point update on segment tree ****//

//For query
int query(int si, int ss, int se, int qs, int qe){
	if(qs>se || qe<ss) return 0; //Needs to be changed
	
	if(qs<=ss && se<=qe) return st[si];
	
	int mid=ss+(se-ss)/2;
	
	int l=query(2*si, ss, mid, qs, qe);
	int r=query(2*si+1, mid+1, se, qs, qe);
	
	return l+r; //Needs to be changed
}

//For point update
void update(int si, int ss, int se, int qi){
	if(ss==se){
		st[si]=arr[ss];
		return;
	}
	
	int mid=ss+(se-ss)/2;
	
	if(qi<=mid) update(2*si, ss, mid, qi);
	else update(2*si+1, mid+1, se, qi);
	
	st[si]=st[2*si]+st[2*si+1]; //Needs to be changed
}

//**** For range query and range update along with updation on lazy segment tree ****//

//For query
int lazy_query(int si, int ss, int se, int qs, int qe){
	if(lazy[si]!=0){
		int dx=lazy[si];
		lazy[si]=0;
		st[si]+=dx*(se-ss+1);
		if(ss!=se){
			lazy[2*si]+=dx;
			lazy[2*si+1]+=dx;
		}
	}
	
	if(qs>se || qe<ss) return 0; //Needs to be changed
	
	if(qs<=ss && se<=qe) return st[si];
	
	int mid=ss+(se-ss)/2;
	
	int l=lazy_query(2*si, ss, mid, qs, qe);
	int r=lazy_query(2*si+1, mid+1, se, qs, qe);
	
	return l+r; //Needs to be changed
}

//For range update
void lazy_update(int si, int ss, int se, int qs, int qe, int val){
	if(lazy[si]!=0){
		int dx=lazy[si];
		lazy[si]=0;
		st[si]+=dx*(se-ss+1);
		if(ss!=se){
			lazy[2*si]+=dx;
			lazy[2*si+1]+=dx;
		}
	}
	
	if(qs>se || qe<ss) return;
	
	if(qs<=ss && se<=qe){
		int dx=val;
		st[si]+=dx*(se-ss+1);
		if(ss!=se){
			lazy[2*si]+=dx;
			lazy[2*si+1]+=dx;
		}
		return;
	}
	
	int mid=ss+(se-ss)/2;
	
	lazy_update(2*si, ss, mid, qs, qe, val);
	lazy_update(2*si+1, mid+1, se, qs, qe, val);
	
	st[si]=st[2*si]+st[2*si+1]; //Needs to be changed
}

int main(){
	
}
