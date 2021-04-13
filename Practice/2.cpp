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
#define rep(i, a, b) for(int i=a; i<b; i++)
#define rrep(i, a, b) for(int i=b; i>=a; i--)
//#define endl "\n"

//****DO NOT TOUCH ABOVE THIS LINE****//
//#define kk

const int maxN=2e5+5;

void solve(){
	string s,t;
	getline(cin, s);
	getline(cin, t);
	
	map<char, int> heading, text;
	
	for(auto c: s) heading[c]++;
	
	for(auto c: t) text[c]++;
	
	for(auto p: text){
		char c=p.ff;
		int d=p.ss;
		
		if(c!=' ' && heading[c]<d){
			cout<<"NO"<<endl;
			return;
		}
	}
	
	cout<<"YES"<<endl;
}

//****DO NOT TOUCH BELOW THIS LINE****//

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cout<<fixed<<setprecision(5);

	#ifdef kk
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	//preprocess();
		
	int T=1;
	//cin>>T;

	while(T--){
		solve();
	}
}
