#include <bits/stdc++.h>
using namespace std;

#define kk
#define pi pair<int, int>

// *************************** METHOD1 **************************** //

/*
//Problem: Given an array of N elements and you have to answer Q queries of the form L R K.
//         Count the numbers smaller than K in range L to R.

//Approach: We will use here Merge Sort Tree to solve the problem

//Key Idea: The key idea is to build a Segment Tree with a vector at every node and the 
//           vector contains all the elements of the sub-range in a sorted order

//Analogy: The structure of segment tree formed here is some what similar to the tree formed
//         during the merge sort algorithm. That's why they are called Merge Sort Trees. 

const int maxN=2e5+5;

int A[maxN];
int B[maxN];
pi arr[maxN];

vector<int> st[4*maxN];

int n;
vector<int> merge(vector<int> &l, vector<int> &r){
	vector<int> v;
	int i=0, j=0;
	
	while(i<l.size() && j<r.size()){
		if(l[i]<=r[j]){
			v.push_back(l[i]);
			i++;
		}
		else{
			v.push_back(r[j]);
			j++;
		}
	}
	
	while(i<l.size()){
		v.push_back(l[i]);
		i++;
	}
	
	while(j<r.size()){
		v.push_back(r[j]);
		j++;
	}
	
	return v;
}

void build(int si, int ss, int se){
	if(ss==se){
		st[si].push_back(arr[ss].second);
		return;
	}
	
	int mid=ss+(se-ss)/2;
	
	build(2*si, ss, mid);
	build(2*si+1, mid+1, se);
	
	st[si]=merge(st[2*si], st[2*si+1]);
}

int query(int si, int ss, int se, int qs, int qe, int k){
	if(qs>se || qe<ss) return 0;
	
	if(qs<=ss && se<=qe){
		return st[si].end() - upper_bound(st[si].begin(), st[si].end(), k);
	}
	
	int mid=ss+(se-ss)/2;
	
	int l=query(2*si, ss, mid, qs, qe, k);
	int r=query(2*si+1, mid+1, se, qs, qe, k);
	
	return l+r;
}

int main(){
	#ifdef kk
	freopen("input.txt", "r", stdin);
	#endif
	
	cin>>n;
	
	for(int i=1; i<=n; i++){
		cin>>A[i];
	}
	
	for(int i=1; i<=n; i++){
		cin>>B[i];
	}
	
	for(int i=1; i<=n; i++){
		arr[i]={A[i], B[i]};
	}
	
	sort(A+1, A+n+1);
	sort(arr+1, arr+n+1);
	
	build(1, 1, n);
	
	int q;
	cin>>q;
	
	while(q--){
		int s, l;
		cin>>s>>l;
		
		int x=upper_bound(A+1, A+n+1, s) - (A+1);
		x++;
		
		cout<<query(1, 1, n, x, n, l)<<" ";
	}
}
//Input:
//5
//16 11 10 20 18
//11 9 2 2 4
//5
//3 20
//4 5
//9 1
//4 6
//8 4

*/

// ********************* ------END1-------- *********************** //

/*
// APPLICATION OF MERGE SORT TREE
  
//Problem: Find the kth smallest element in the array in the range [qs, qe] in the given array.

//Merge Sort Tree is built on the "indices of elments" instead of the "values of elements" of the array
void build(int si, int ss, int se) {
	if(ss==se) {
		st[si].push_back(arr[i].second);  // arr[i]={A[i], i}
		return;
	}
	
	int mid=ss+(se-ss)/2;
	
	build(2*si, ss, mid);
	build(2*si+1, mid+1, se);
	
	merge(st[2*si].begin(), st[2*si].end(), st[2*si+1].begin(), seg[2*si+1].end(), back_inserter(st[si]));
}

//Below function will return the "index" of kth smallest element in the array in the range [qs, qe]
int query_kth(int si, int ss, int se, int qs, int qe, int k) {
	if(ss==se) return st[si][0];
	
	int mid=ss+(se-ss)/2;
	
	auto it=upper_bound(st[2*si].begin(), seg[2*si].end(), qe);
	int total=it - lower_bound(st[2*si].begin(), st[2*si].end(), qs);
	
	if(total>=k) return query_kth(2*si, ss, mid, qs, qe, k);
	else return query_kth(2*si+1, mid+1, se, qs, qe, k-total);
}

*/

// **************************** METHOD2 ***************************** //

//Problem: Given an array of N elements and you have to answer Q queries of the form L R K.
//         Count the numbers smaller than K in range L to R.

//Approach: We will use here offline queries and Fenwick Trees

//Key Idea: The key observation here is that since the array of the structure has been sorted
//          in descending order. Whenever we encounter any query only the elements which are greater
//          than ‘k’ comprises the count in the "ft" array which is the answer that is needed.

//Analogy: In some questions, it is hard to answer queries in any random order. So instead of
//         answering each query separately, store all the queries and then order them accordingly
//         to calculate answer for them efficiently. Store all the answers and then output it in
//         the order it was initially given. This technique is called Offline Query, that is,
//         the answer of one query does not depend on the answers of previous queries.

struct node{
	int val; // stores ‘k’ of the query, in case of array elements it stores their values
	int l; // stores the starting index of query, in case of array elements it is kept as 0
	int r; // stores the ending index of query, in case of array elements it stores their position in array
	int pos; // stores the order of query, in case of array elements it is kept as 0
};

const int maxN=2e5+5;

int A[maxN];
int B[maxN];
pi arr[maxN];
vector<int> Q[maxN];

node C[maxN];
int ft[maxN];
int ans[maxN];

int n;
void update(int i, int k){
	while(i<=n){
		ft[i]+=k;
		i+=(i)&(-i);
	}
}

int query(int i){
	int sum=0;
	
	while(i>0){
		sum+=ft[i];
		i-=(i)&(-i);
	}
	
	return sum;
}

bool comp(node &a, node &b){
	if(a.val==b.val) return a.l>b.l;
	return a.val>b.val;
}

int main(){
	#ifdef kk
	freopen("input.txt", "r", stdin);
	#endif
	
	cin>>n;
	
	for(int i=1; i<=n; i++){
		cin>>A[i];
	}
	
	for(int i=1; i<=n; i++){
		cin>>B[i];
	}
	
	for(int i=1; i<=n; i++){
		arr[i]={A[i], B[i]};
	}
	
	sort(A+1, A+n+1);
	sort(arr+1, arr+n+1);
	
	int q, u=1, v=1;
	cin>>q;
	
	while(u<=q){
		int s, l;
		cin>>s>>l;
		
		int x=upper_bound(A+1, A+n+1, s) - (A+1);
		x++;
		
		Q[v]={x, n, l};
		u++, v++;
	}
	
	for(int i=1; i<=n; i++){
		C[i].val=arr[i].second;
		C[i].l=0;
		C[i].r=i;
		C[i].pos=0;
	}
	
	for(int i=n+1; i<=n+q; i++){
		C[i].val=Q[i-n][2];
		C[i].l=Q[i-n][0];
		C[i].r=Q[i-n][1];
		C[i].pos=i-n;
	}
	
	sort(C+1, C+n+q+1, comp); // WE SOLVE FOR QUERIES HAVING LARGEST VALUE OF "k" FIRST
	
	for(int i=1; i<=n+q; i++){
		if(C[i].pos==0){
			update(C[i].r, 1);
		}
		else{ 
			int x=query(C[i].r)-query(C[i].l-1);
			ans[C[i].pos]=x;
		}
	}
	
	for(int i=1; i<=q; i++) cout<<ans[i]<<" ";
}
// ********************* --------END2-------- *********************** //
