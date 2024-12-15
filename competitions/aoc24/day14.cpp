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

struct PointVelocity {
    int px, py; 
    int vx, vy; 
};


void solve_part_a(vector<PointVelocity> data){
    int wide=101,tall=103;
    
    for(int k=1; k<=100; k++){
    	for(PointVelocity &p: data){
	    	int a=(p.px+p.vx+wide)%wide, b=(p.py+p.vy+tall)%tall;
	    	p.px=a;
	    	p.py=b;
	    }
    }
    
    vector<int> quad(4);
    
    for(PointVelocity p: data){
    	if(p.px == wide/2 || p.py == tall/2) continue;
    	
    	if(0<=p.px && p.px<wide/2 && 0<=p.py && p.py<tall/2) quad[0]++;
    	if(0<=p.px && p.px<wide/2 && tall/2<p.py && p.py<tall) quad[1]++;
    	if(wide/2<p.px && p.px<wide && tall/2<p.py && p.py<tall) quad[2]++;
    	if(wide/2<p.px && p.px<wide && 0<=p.py && p.py<tall/2) quad[3]++;
    }
    
    int ans=1;
    
    for(int c: quad){
    	if(c!=0) ans*=c;
    }
    
    cout<<ans;
}


void solve_part_b(vector<PointVelocity> data){
	int wide=101,tall=103;
	
	int time=0;
	
	map<pair<int,int>,int> mp;
	
	while(true){
		for(PointVelocity p: data){
	    	mp[{p.px,p.py}]++;
	    }
		cout<<"After seconds: "<<time<<"\n";
		// std::this_thread::sleep_for(std::chrono::milliseconds(800));
		time++;
	    
		for(int i=0; i<tall; i++){
			for(int j=0; j<wide; j++){
				if(mp.find({j,i})!=mp.end()){
					cout<<"*";
				}
				else{
					cout<<".";
				}
			}
			cout<<"\n";
		}

		cout<<"\n\n";
		
		for(PointVelocity &p: data){
	    	int a=(p.px+p.vx+wide)%wide, b=(p.py+p.vy+tall)%tall;
			mp[{p.px,p.py}]--;
			if(mp[{p.px,p.py}]==0) mp.erase({p.px,p.py});
	    	p.px=a;
	    	p.py=b;
	    }
	}
}

void solve(){
	std::string line;
    std::vector<PointVelocity> data; 

    while (std::getline(std::cin, line)) {
        PointVelocity pv;
        char temp; // Temporary variable to skip characters (e.g., 'p=', 'v=') in the input

        // Parse the line using istringstream
        std::istringstream stream(line);
        stream >> temp >> temp >> pv.px >> temp >> pv.py;  // Read p=x,y
        stream >> temp >> temp >> pv.vx >> temp >> pv.vy;  // Read v=x',y'

        // Add the parsed data to the vector
        data.push_back(pv);
    }
    
	// solve_part_a(data);
	solve_part_b(data);
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
