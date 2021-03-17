#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define ff first
#define ss second

const int maxN=1e5+5;

vector<pi> arr[maxN];
int dist[maxN];

void bfs(int v){
	deque<int> dq;
	dist[v]=0;
	dq.push_back(v);
	
	while(!dq.empty()){
		v=dq.front();
		dq.pop_front();
		
		for(auto c: arr[v]){
			int child=c.ff;
			int weight=c.ss;
	
			if(dist[child]>dist[v]+weight){
				dist[child]=dist[v]+weight;
				
				if(weight==0) dq.push_front(child);
				else dq.push_back(child);
			}
		}
	}
}

int main(){
	int n, m;
	cin>>n>>m;
	
	for(int i=1; i<=m; i++){
		int a, b, w;
		cin>>a>>b>>w;
		++a, ++b;     // 1-based indexing
		arr[a].push_back({b, w});
	}
	
	for(int i=1; i<=n; i++){
		dist[i]=INT_MAX;
	}
	
	bfs(1);
	
	cout<<"Minimum distance from node 1 to all the other nodes in the graph having edges"<<endl;
	cout<<"with weights 0 and 1 only:"<<endl;
	
	for(int i=1; i<=n; i++){
		cout<<dist[i]<<" ";
	}
}

/* Input:
9 13
0 1 0
0 7 1
1 7 1
1 2 1
2 3 0
2 5 0
2 8 1
3 4 1
3 5 1 
4 5 1
5 6 1
6 7 1 
7 8 1
*/
