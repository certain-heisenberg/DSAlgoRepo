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
int dy[4]={0,-1,0,1};
char dir[4]={'D','L','U','R'};
 
//****DO NOT TOUCH ABOVE THIS LINE****//
 
const int maxN=1e5+5;

void solve_part_a(vector<vector<char>> &v, string pattern){
	
	int si=-1, sj=-1;
	int n=v.size(), m=v[0].size();
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(v[i][j]=='@'){
				si=i,sj=j;
				v[i][j]='.';
				break;
			}
		}
	}
	
	for(char c: pattern){
		int dirIdx = -1;
		if(c=='<'){
			dirIdx=1;
		}
		else if(c=='>'){
			dirIdx=3;
		}
		else if(c=='^'){
			dirIdx=2;
		}
		else{
			dirIdx=0;
		}
		
		// cout<<c<<" -- "<<dirIdx<<"\n";
		
		vector<pair<int,int>> objPos;
		
		int tempSi=si, tempSj=sj;
		int shiftSiTo=-1, shiftSjTo=-1;
		
		
		while(true){
			int a=tempSi+dx[dirIdx], b=tempSj+dy[dirIdx];
			if(v[a][b]=='#'){
				break;
			}
			
			if(v[a][b]=='.'){
				shiftSiTo=a, shiftSjTo=b;
				break;
			}
			
			tempSi=a,tempSj=b;
		}
		
		tempSi=si, tempSj=sj;
		
		if(shiftSiTo!=-1 && shiftSjTo!=-1){
			while(true){
				if(tempSi==shiftSiTo && tempSj==shiftSjTo){
					break;
				}
				if(v[tempSi][tempSj]=='O'){
					objPos.push_back({tempSi,tempSj});
				}
				
				tempSi+=dx[dirIdx];
				tempSj+=dy[dirIdx];
			}
		}
			
		
		reverse(objPos.begin(),objPos.end());
		for(auto p: objPos){
			int a=p.first+dx[dirIdx];
			int b=p.second+dy[dirIdx];
			
			v[p.first][p.second]='.';
			v[a][b]='O';
		}
		
		tempSi=si+dx[dirIdx];
		tempSj=sj+dy[dirIdx];
		
		if(v[tempSi][tempSj]!='O' && v[tempSi][tempSj]!='#'){
			si=tempSi;
			sj=tempSj;
		}
		
		// for(int i=0; i<n; i++){
		// 	for(int j=0; j<m; j++){
		// 		if(si==i && sj==j){
		// 			cout<<"@";
		// 		}
		// 		else{
		// 			cout<<v[i][j];
		// 		}
		// 	}
		// 	cout<<"\n";
		// }
		
		// cout<<"\n\n";
		
	}
	
	int ans=0;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(v[i][j]=='O'){
				ans+=100*i+j;
			}
		}
	}
	
	cout<<ans<<"\n";
}

void solve_part_b(vector<vector<char>> v, string pattern){
	vector<vector<char>> u;
	for(int i=0; i<v.size(); i++){
		vector<char> temp;
		for(char c: v[i]){
			if(c=='#'){
				temp.push_back('#');
				temp.push_back('#');
			}
			else if(c=='O'){
				temp.push_back('[');
				temp.push_back(']');
			}
			else if(c=='.'){
				temp.push_back('.');
				temp.push_back('.');
			}
			else if(c=='@'){
				temp.push_back('@');
				temp.push_back('.');
			}
		}
		u.push_back(temp);
	}

	int si=-1, sj=-1;
	int n=u.size(), m=u[0].size();
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(u[i][j]=='@'){
				si=i,sj=j;
				u[i][j]='.';
				break;
			}
		}
	}

	
}

void solve(){
	string line;
	vector<vector<char>> v;
	
	while(getline(cin,line)){
		if(!line.empty()){
			vector<char> temp;
			for(char c: line){
				temp.push_back(c);
			}
			v.push_back(temp);
		}
		else{
			break;
		}
	}
	
	string pattern;
	getline(cin,pattern);
	
	solve_part_a(v, pattern);
	solve_part_b(v, pattern);
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
