#include <bits/stdc++.h>
using namespace std;

int N, M;
char arr[1001][1001];
int vis[1001][1001];

bool isValid(int x, int y){
    if(x<1 || x>N || y<1 || y>M) return false;
    
    if(vis[x][y]==1 || arr[x][y]=='#') return false;
    return true;
}

void dfs(int x, int y){
    int dx[]={-1, 0, 1, 0};
    int dy[]={0, 1, 0, -1};
    vis[x][y]=1;
    for(int i=0; i<4; i++){
        if(isValid(x+dx[i], y+dy[i])){
            dfs(x+dx[i], y+dy[i]);
        }
    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            char c;
            cin>>c;
            arr[i][j]=c;
        }
    }
    N=n, M=m;
    int count=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(vis[i][j]==0 && arr[i][j]=='.'){
                count++;
                dfs(i,j);
            }
        }
    }
    cout<<count<<endl;
}
