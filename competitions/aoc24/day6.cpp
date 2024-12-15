#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ff first
#define ss second
#define pi pair<int, int>
#define inf 1000000000
#define mod 1000000007
#define all(a) a.begin(), a.end()

int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
char dir[4]={'D','L','U','R'};

const int maxN=1e5+5;

void solve_part_a(vector<vector<char>> &v){
    int si=-1, sj=-1;
    int n=v.size(), m=v[0].size();
	set<pair<int,int>> st;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(v[i][j]=='^'){
				si=i, sj=j;
				v[i][j]='.';
				break;
			}
		}
	}
	
	
	int ans=0;
	char curDir='U';
	while(true){
		ans++;
		st.insert({si,sj});
		
		if(curDir=='U' && si==0){
			break;
		}
		if(curDir=='D' && si==n-1){
			break;
		}
		if(curDir=='L' && sj==0){
			break;
		}
		if(curDir=='R' && sj==m-1){
			break;
		}
		
		for(int i=0; i<4; i++){
			if(curDir == dir[i]){
				int a=si+dx[i];
				int b=sj+dy[i];
				
				if(v[a][b]=='#'){
					int dirIndex=(i+1)%4;
					curDir=dir[dirIndex];
					si=si+dx[dirIndex];
					sj=sj+dy[dirIndex];
				}
				else{
					si=a;
					sj=b;
				}
				break;
			}
		}
	}
	
	cout<<st.size()<<"\n";
}

void solve_part_b(vector<vector<char>> &v){

}

void solve(){
	string line;
	vector<vector<char>> v;
	
	while(getline(cin,line)){
		vector<char> temp;
		for(char c: line){
			temp.push_back(c);
		}
		v.push_back(temp);
	}

    solve_part_a(v);
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cout<<fixed<<setprecision(5);

	#ifdef kk
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int T=1, i=1;
	// cin>>T;

	while(i<=T){
		solve();
		i++;
	}
}

