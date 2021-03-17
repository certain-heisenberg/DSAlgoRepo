#include <bits/stdc++.h>
using namespace std;

//Object Oriented Implementation to Detect cycle in a Directed Graph using 3 colors

enum Color{white, grey, black};

class Graph{
	int n;
	vector<int> *arr;
	bool dfs(int v, int color[]);
	
	public:
	Graph(int a);
	
	void add_edge(int a, int b);
	
	bool isCyclic();
};

Graph::Graph(int a){
	this->n=a;
	arr=new vector<int>[a+1];
}

void Graph::add_edge(int a, int b){
	arr[a].push_back(b);
}

bool Graph::dfs(int v, int color[]){
	color[v]=grey;
	
	for(int child: arr[v]){
		if(color[child]==grey) return true;
		else if(color[child]==white && dfs(child, color)) return true;
	}
	
	color[v]=black;
	return false;
}

bool Graph::isCyclic(){
	int *color=new int[n+1];
	
	for(int i=1; i<=n; i++){
		color[i]=white;
	}
	
	for(int i=1; i<=n; i++){
		if(color[i]==white && dfs(i, color)) return true;
	}
	
	return false;
}

int main(){
	int n, m;
	cin>>n>>m;
	
	Graph g(n);
	
	for(int i=1; i<=m; i++){
		int a, b;
		cin>>a>>b;
		g.add_edge(a, b);
	}
	
	bool x=g.isCyclic();
	
	if(x) cout<<"Graph contains cycle."<<endl;
	else cout<<"Graph doesn't contain cycle."<<endl;
}
