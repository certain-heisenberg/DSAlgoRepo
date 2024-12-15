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

const ll INF=1e18+5;

const int naxN=2e1+5;
const int maxN=2e5+5;

//int dx[8]={-1, -1, -1, 0, 1, 1, 1, 0};
//int dy[8]={-1, 0, 1, 1, 1, 0, -1, -1};
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

bool isValid(int a, int b, int n, int m){
	if(a<0 || a>=n || b<0 || b>=m) return false;
	return true;
}

//****DO NOT TOUCH ABOVE THIS LINE****//


struct PairComparator {
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) const {
        if (lhs.first != rhs.first) {
            return lhs.first < rhs.first;
        }
        return lhs.second > rhs.second;
    }
};

void solve_part_a(string s){
}

void solve_part_b(string s){
    vector<string> str;
	
	int id=0;
	
	vector<vector<int>> full;
	
	int index=0;
	
	priority_queue<pair<int, int>, std::vector<pair<int, int>>, PairComparator> maxHeap;
	
	for(int i=0; i<(int)s.size(); i++){
		int diskSize = s[i]-'0';
		if(i%2==0){
			for(int j=0; j<diskSize; j++){
				str.push_back(to_string(id));
			}
			
			full.push_back({index,diskSize,id});
			id++;
		}
		else{
			for(int j=0; j<diskSize; j++){
				str.push_back(".");
			}
			if(diskSize>0) maxHeap.push({diskSize,index});
		}
		
		index+=diskSize;
	}
	
	for(int lf=full.size()-1; lf>=0; lf--){
		vector<pair<int,int>> temp;
		
		int minIndex=-1, minVal;
		
		while(!maxHeap.empty()){
			auto p = maxHeap.top();
			if(p.first<full[lf][1]){
				break;
			}
			maxHeap.pop();
			temp.push_back({p.first,p.second});
			if(p.first>=full[lf][1] && (minIndex==-1 || minIndex>p.second)){
				minVal=p.first;
				minIndex=p.second;
			}
		}
		
		while(!temp.empty()){
			auto p=temp.back();
			temp.pop_back();
			if(p.second==minIndex){
				continue;
			}
			else{
				maxHeap.push({p.first,p.second});
			}
		}
		
		if(minIndex==-1 || minIndex >= full[lf][0]){
			continue;
		}
		
		int k=minIndex;
		for(int i=0; i<full[lf][1]; i++){
			str[k]=to_string(full[lf][2]);
			k++;
		}
		
		k=full[lf][0];
		for(int i=0; i<full[lf][1]; i++){
			str[k]=".";
			k++;
		}
		
		if(minVal - full[lf][1]>0) maxHeap.push({minVal - full[lf][1], minIndex + full[lf][1]});
	}
		
	int ans=0;
	
	for(int i=0; i<(int)str.size(); i++){
		if(str[i]!="."){
			ans+=(i*(stoi(str[i])));
		}
	}
	
	cout<<ans<<"\n";
}

void solve(){
	string s;
	cin>>s;

    solve_part_a(s);
    solve_part_b(s);
}

//****DO NOT TOUCH BELOW THIS LINE****//

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cout<<fixed<<setprecision(18);

	#ifdef kk
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	//preprocess();
		
	int T=1, i=1;
	// cin>>T;

	while(i<=T){
		solve();
		i++;
	}
}
