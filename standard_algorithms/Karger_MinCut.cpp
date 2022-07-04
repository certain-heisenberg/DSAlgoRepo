//Input:
//5 7
//01 03 04 12 13 23 34

//Minimum Cut required for the above input is 2

#include <bits/stdc++.h>
using namespace std;
 
//#define kk

int par[31];
int R[31];

int find(int a){
	if(par[a]<0) return a;
	return par[a]=find(par[a]);
}

void merge(int a, int b){
	a=find(a);
	b=find(b);
	
	if(a==b) return;
	
	if(R[a]>=R[b]){
		par[b]=a;
		R[a]+=R[b];
	}
	else{
		par[a]=b;
		R[b]+=R[a];
	}
}

string edges[61];

void solve(){
	//n - number of vetices
	//m - number of edges
	int n, m;
	cin>>n>>m;
	
	for(int i=0; i<n; i++){
		par[i]=-1;
		R[i]=1;
	}
	
	for(int i=0; i<m; i++){
		cin>>edges[i];
	}
	
	//Karger’s Algo
	
	srand((unsigned) time(0)); //Initial seeding to srand()
	
	int v=n;
	
	while(v>2){
		int x=rand() % m;
		
		int a=edges[x][0]-'0', b=edges[x][1]-'0';
		
		merge(a, b);
		v--;
	}
	
	int min_cut=0;
	for(int i=0; i<m; i++){
		int a=edges[i][0]-'0', b=edges[i][1]-'0';
		
		a=find(a);
		b=find(b);
		if(a!=b) min_cut++;
	}
	
	cout<<min_cut<<endl;
}
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cout<<fixed<<setprecision(6);
	
	#ifdef kk
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif
	
	int T=1;
	//cin>>T;
	
	while(T--){		
		solve();
	}
}
