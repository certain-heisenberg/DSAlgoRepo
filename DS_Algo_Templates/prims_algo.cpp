#include <bits/stdc++.h>
using namespace std;

const int maxN=1e5+5;

vector<pair<int,int>> arr[maxN];
int par[maxN];
int dist[maxN];
bool vis[maxN];

int getMinNode(int n){
    int minDist=INT_MAX, node=-1;

    for(int i=1; i<=n; i++){
        if(vis[i]==false && dist[i]<minDist){
            minDist=dist[i];
            node=i;
        }
    }

    return node;
}

void prims(int n){
    for(int i=1; i<=n; i++){
        dist[i]=INT_MAX;
    }

    par[1]=-1;
    dist[1]=0;

    for(int i=1; i<n; i++){
        int node=getMinNode(n);
        vis[node]=true;

        for(auto child: arr[node]){
            int childNode=child.first;
            int wt=child.second;
            if(vis[childNode]==false && wt<dist[childNode]){
                dist[childNode]=wt;
                par[childNode]=node;
            }
        }
    }
}


int main(){
    int n,m;
    cin>>n>>m;

    for(int i=1; i<=m; i++){
        int a,b,w;
        cin>>a>>b>>w;

        arr[a].push_back({b,w});
        arr[b].push_back({a,w});
    }

    prims(n);

    for(int i=1; i<=n; i++){
        cout<<par[i]<<" ";
    }

    cout<<"\n\n";

    for(int i=1; i<=n; i++){
        cout<<dist[i]<<" ";
    }
}

/*

5 14
1 2 2
1 4 6
2 1 2
2 3 3
2 4 8
2 5 5
5 3 7
5 4 9
3 2 3
3 5 7
4 1 6
4 2 8
4 5 9
5 2 5

*/