#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

const int maxN=1e5+5;

int arr[maxN];
int ft[maxN]; // ft - Fenwick Tree or Binary Indexed Tree
int n;

// (#) Point Update and Range Query
void update(int i, int val){
	while(i<=n){
		ft[i]+=val;
		i+=i & (-i);
	}
}

int query(int i){      //returns sum of values in the range [1, i]
	int sum=0;
	
	while(i>0){
		sum+=ft[i];
		i-=i & (-i);
	}
	return sum;
}

// (#) [Multiple] Range Update and [Multiple] Point Queries
void range_update(int l, int r, int k){
	update(l, k);
	update(r+1, -k);
}

int point_query(int i){
	return query(i);
}

// (#) [Multiple] Range Update and [Multiple] Range Queries
//NOTE:: This is discussed at the bottom of this notebook


// (#) Build Fenwick Tree (Initialisation)
void build(){
	for(int i=1; i<=n; i++){
		update(i, arr[i]);
	}
}

signed main(){
	cin>>n;
	
	// Input: 2 1 1 3 2 3 4 5 6 7 8 9
	
	for(int i=1; i<=n; i++) cin>>arr[i];
	
	build();
	
	cout<<query(6)<<endl;
	
	update(4, 6);
	
	cout<<query(6)<<endl;
}

/* ************************* END  ************************** */

/* ********* Fenwick Tree to find minimum value in the range [1, r] in 1-D array **************** */

const int maxN=1e5+5;

int arr[maxN];
int ft[maxN]; // ft - Fenwick Tree or Binary Indexed Tree
int n;

void update_min(int i, int val){
	while(i<=n){
		ft[i]=min(ft[i], val);
		i+=i & (-i);
	}
}

int query_min(int i){
	int ans=INT_MAX;
	
	while(i>0){
		ans=min(ft[i], ans);
		i-=i & (-i);
	}
	
	return ans;
}


void build_min(){
	for(int i=1; i<=n; i++){
		update_min(i, arr[i]);
	}
	
	//NOTE:: Each time a value is updated, the new value has to be smaller than the current value at 
	//       that index because the min function is not reversible.
}

signed main(){
	cin>>n;
	
	// Input: 2 1 1 3 2 3 4 5 6 7 8 9
	
	for(int i=1; i<=n; i++) cin>>arr[i];
	
	for(int i=1; i<=n; i++) ft[i]=INT_MAX;
	
	build_min();
	
	cout<<query(6)<<endl;
	
	update(4, 6);
	
	cout<<query(6)<<endl;
}

/* ************************* END  ************************** */


/* *************** Fenwick Tree for Multidimensional Array ********************* */

//NOTE:: Here we will find sum in 2-D Array

int ft[1000][1000];

void update_2d(int i, int j, int val){
	while(i<=n){
		while(j<=n){
			ft[i][j]+=val;
			j+=j & (-j);
		}
		i+=i & (-i);
	}	
}

int query_2d(int i, int j){
	int sum=0;
	
	while(i>0){
		while(j>0){
			sum+=ft[i][j];
			j-=j & (-j);
		}
		i-=i & (-i);
	}
	
	return sum;
}

/* ************************* END  ************************** */


// (#) [Multiple] Range Updates and [Multiple] Range Queries

//To support both [Multiple] Range Updates and [Multiple] Range Queres, two Fenwick Tress are needed
//Namely ft1[] and ft2[], initialized with zeros
const int maxN=1e5+5;

int ft1[maxN];
int ft2[maxN];
int n;

//Same update() and query() functions of ordinary Fenwick Tree are implemented first 
//with slight modifications

void update(int ft[], int i, int val){
	while(i<=n){
		ft[i]+=val;
		i+=i & (-i);
	}
}

int query(int ft[], int i){
	int sum=0;
	
	while(i>0){
		sum+=ft[i];
		i-=i & (-i);
	}
	return sum;
}

//And also additional funtions for "range_update()" and "range_query()" are implemented
void range_update(int l, int r, int k){
	update(ft1, l, k);
	update(ft1, r+1, -k);
	update(ft2, l, k*(l-1));
	update(ft2, r+1, -k*r);
}

int prefix_query(int i){     //returns sum of values in the range [1, i]
	return query(ft1, i)*i - query(ft2, i);
}

int range_query(int l, int r){      //returns sum of values in the range [l, r]
	return prefix_query(r)-prefix_query(l-1);
}

void build_tree(){
	for(int i=1; i<=n; i++){
		range_update(i, i, arr[i]);
	}
}