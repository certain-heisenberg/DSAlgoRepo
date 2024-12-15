#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define mat vector<vector<int>>
#define vi vector<int>
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define pi pair<int, int>
#define inf 1000000000
#define mod 1000000007
#define rep(i,a,b) for(int i=a; i<=b; i++)
#define rrep(i,b,a) for(int i=b; i>=a; i--)
#define all(a) a.begin(), a.end()
 
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
char dir[4]={'D','R','U','L'};
 
//****DO NOT TOUCH ABOVE THIS LINE****//
 
const int maxN=1e5+5;

void dfs(vector<vector<char>> &v, vector<vector<bool>> &vis, int x, int y, vector<pair<int,int>> &st, int &cnt){
	vis[x][y]=true;
	
	cnt++;
	
	for(int i=0; i<4; i++){
		int a=x+dx[i];
		int b=y+dy[i];
		
		if(a<0 || b<0 || a>=v.size() || b>=v[0].size() || v[a][b]!=v[x][y]){
			st.push_back({a,b});
			continue;
		}
		
		if(!vis[a][b]) dfs(v,vis,a,b,st,cnt);
	}
}

void solve_part_a(vector<vector<char>> &v){
	int n=v.size(), m=v[0].size();
	
	vector<vector<bool>> vis(n,vector<bool> (m,false));
	
	int ans=0;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(!vis[i][j]){
				int cnt=0;
				vector<pair<int,int>> st;
				dfs(v,vis,i,j,st,cnt);
				
				ans+=cnt*st.size();	
			}
		}
	}
	
	cout<<ans<<"\n";
}

void solve_part_b(vector<vector<char>> &v){
	int n=v.size(), m=v[0].size();
	
	vector<vector<bool>> vis(n,vector<bool> (m,false));
	
	int ans=0;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(!vis[i][j]){
				int cnt=0;
				vector<pair<int,int>> st;
				dfs(v,vis,i,j,st,cnt);
				
				map<int,vector<int>> mp1,mp2;
				
				for(auto p: st){
					mp1[p.first].push_back(p.second);
					mp2[p.second].push_back(p.first);
				}
				
				int tempAns=0;
				
				// if(v[i][j]=='F'){
					for(auto &p: mp1){
						int up=p.first-1;
						int down=p.first+1;
						
						vector<int> valid;
						sort(p.second.begin(),p.second.end());
						
						set<int> isUpValid;
						set<int> isDownValid;
						
						for(int c: p.second){
							if(c<0 || c>=v[0].size()){
								
								continue;
							}
							
							if(isUpValid.find(c)==isUpValid.end() && up>=0 && up<v.size() && v[up][c]==v[i][j]){
								valid.push_back(c);
								isUpValid.insert(c);
								continue;
							}
							
							if(isDownValid.find(c)==isDownValid.end() && down>=0 && down<v.size() && v[down][c]==v[i][j]){
								valid.push_back(c);
								isDownValid.insert(c);
								continue;
							}
						}
						
						p.second=valid;
					}
				
					for(auto p: mp1){
						int temp=0;
						int prev=-3;
						cout<<p.first<<" -> ";
						for(int c: p.second){
							if(c!=prev+1){
								temp++;
							}
							prev=c;
							
							cout<<c<<" ";
						}
						tempAns+=temp;
						cout<<"| "<<temp<<"\n";
					}
					
					cout<<"\n";
					
					
					for(auto &p: mp2){
						int left=p.first-1;
						int right=p.first+1;
						
						vector<int> valid;
						sort(p.second.begin(),p.second.end());
						set<int> isLeftValid;
						set<int> isRightValid;
						
						for(int c: p.second){
							if(c<0 || c>=v.size()){
								continue;
							}
							
							if(isLeftValid.find(c)==isLeftValid.end() && left>=0 && left<v[0].size() && v[c][left]==v[i][j]){
								valid.push_back(c);
								isLeftValid.insert(c);
								continue;
							}
							
							if(isRightValid.find(c)==isRightValid.end() && right>=0 && right<v[0].size() && v[c][right]==v[i][j]){
								valid.push_back(c);
								isRightValid.insert(c);
								continue;
							}
						}
						
						p.second=valid;
					}
				
					for(auto p: mp2){
						int temp=0;
						int prev=-3;
						cout<<p.first<<" -> ";
						for(int c: p.second){
							if(c!=prev+1){
								temp++;
							}
							prev=c;
							
							cout<<c<<" ";
						}
						tempAns+=temp;
						cout<<"| "<<temp<<"\n";
					}
				// }

				ans+=cnt*tempAns;	
				cout<<v[i][j]<<" "<<cnt<<" "<<tempAns<<"\n";
			}
		}
	}
	
	
	// for(int i=0; i<n; i++){
	// 	for(int j=0; j<m; j++){
	// 		if(v[i][j]=='F'){
	// 			cout<<"F";
	// 		}
	// 		else{
	// 			cout<<".";
	// 		}
	// 	}
	// 	cout<<"\n";
	// }
	
	cout<<ans<<"\n";
	
}

void solve(){
	vector<vector<char>> v;
	string line;
	
	while(getline(cin, line)){
		vector<char> temp;
		for(int i=0; i<line.size(); i++){
			temp.push_back(line[i]);
		}
		v.push_back(temp);
	}

	solve_part_a(v);
	solve_part_a(v);
}
 
//****DO NOT TOUCH BELOW THIS LINE****//
 
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
