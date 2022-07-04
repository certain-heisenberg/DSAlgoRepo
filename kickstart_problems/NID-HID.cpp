#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define mat vector<vector<int>>
#define vi vector<int>
#define ff first
#define ss second
#define pi pair<int, int>
#define mod 1000000007
//#define endl "\n"

//****DO NOT TOUCH ABOVE THIS LINE****//
#define kk

const int maxN=1e5+5;

string int2bin(int n){
	string res="";
	
	while(n){
		res.push_back(n%2+'0');
		n/=2;
	}
	
	while(res.size()!=8) res.push_back('0');
	
	reverse(res.begin(), res.end());
	
	return res;
}

void solve(){
	int n;
	cin>>n;
	
	vector<pair<string, int>> block(n);
	
	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		int d;
		cin>>d;
		
		block[i]={s, d};
	}
	
	string t;
	cin>>t;
	
	string address="";
	string temp="";

	for(int i=0; i<(int)t.size(); i++){
		if(t[i]=='.') address+=int2bin(stoi(temp)), temp="";
		else temp.push_back(t[i]); 
	}
	address+=int2bin(stoi(temp));
	
	int ans=-1, maxVal=INT_MIN;
	
	for(int i=0; i<n; i++){
		string s=block[i].ff;
		int d=block[i].ss;
		
		vector<int> v;
		temp="";
		
		for(int j=0; j<(int)s.size(); j++){
			if(s[j]=='.' || s[j]=='/') v.push_back(stoi(temp)), temp="";
			else temp.push_back(s[j]); 
		}
		v.push_back(stoi(temp));
		
		string ip="";
		
		for(int j=0; j<4; j++){
			ip+=int2bin(v[j]);
		}
		
		string temp_ip=ip;
		string temp_address=address;
		int f=1;
		
		for(int j=ip.size()-1; j>=v[4]; j--){
			temp_ip[j]='0';
			temp_address[j]='0';
		}
		
		for(int j=0; j<(int)ip.size(); j++){
			if(temp_ip[j]!=temp_address[j]){
				f=0;
				break;
			}
		}
		 
		if(f==0) continue;
		else{
			int cnt=0;
			for(int j=0; j<(int)ip.size(); j++){
				if(ip[j]==address[j]) cnt++;
				else break;
			}
			
			if(cnt>maxVal){
				maxVal=cnt;
				ans=d;
			}
		}	
	}
	
	if(ans==-1) cout<<"0"<<endl;
	else cout<<ans<<endl;
}

//****DO NOT TOUCH BELOW THIS LINE****//

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cout<<fixed<<setprecision(18);

	#ifdef kk
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif

	int T=1;
	//cin>>T;

	while(T--){		
		solve();
	}
}

/*
3
192.168.1.32/28 1
192.168.1.0/24 2
192.168.0.0/16 3
192.168.1.33
*/
