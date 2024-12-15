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

void solve_part_a(vector<string> &tokens){
    for(int i=0; i<25; i++){
    	vector<string> temp;
    	
    	for(string s: tokens){
    		int k=s.size();
    		if(s=="0"){
    			temp.push_back("1");
    		}
    		else if(k%2==0){
    			string s1=s.substr(0,k/2);
    			string s2=s.substr(k/2,k/2);
    			temp.push_back(to_string(stoll(s1)));
    			temp.push_back(to_string(stoll(s2)));
    		}
    		else{
    			temp.push_back(to_string(stoll(s)*2024));
    		}
    	}
    	tokens=temp;
    }
    
    cout<<tokens.size()<<"\n";
}

long long recurse(map<pair<long long,int>,long long> &dp, long long val, int iteration){
	string s=to_string(val);
	int k=s.size();
	
	if(iteration == 1){
		if(s=="0"){
			return 1;
		}
		else if(k%2==0){
			return 2;
		}
		else{
			return 1;
		}
	}
	
	if(dp.find({val,iteration})!=dp.end()) return dp[{val,iteration}];
	
	long long tempAns=0;
	
	if(s=="0"){
		tempAns=recurse(dp, 1, iteration-1);
	}
	else if(k%2==0){
		string s1=s.substr(0,k/2);
		string s2=s.substr(k/2,k/2);
		// cout<<iteration<<" "<<s1<<" ---  "<<s2<<"\n";
		tempAns=recurse(dp, stoll(s1), iteration-1)+recurse(dp, stoll(s2), iteration-1);
	}
	else{
		// cout<<iteration<<" "<<stoll(s)*2024<<" |||\n";
		tempAns=recurse(dp, stoll(s)*2024, iteration-1);
	}
	
	// cout<<val<<" **** "<<iteration<<"\n";
	
    return dp[{val,iteration}]=tempAns;
}

void solve_part_b(vector<string> &tokens){
	map<pair<int,int>,int> dp;
	long long ans=0;
	for(string s: tokens){
		ans+=recurse(dp,stoll(s),75);
	}
    
    cout<<ans<<"\n";
}

void solve(){
    string line;
    vector<string> tokens;

    getline(std::cin, line);

    std::istringstream stream(line);
    std::string token;

    while (stream >> token) {
        tokens.push_back(token);
    }

	solve_part_a(tokens);
	// solve_part_b(tokens);
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
