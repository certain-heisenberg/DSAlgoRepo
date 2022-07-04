#include <bits/stdc++.h>
using namespace std;

#define kk
#define int long long

#define int long long
/*
 * Complete the 'initialize' function below.
 *
 * The function accepts STRING s as parameter.
 */
const int maxN=1e5+5;
int arr[maxN][26];

#define mod 1000000007

int fact[maxN];

void compute(){
    fact[0]=1;
    
    for(int i=1; i<maxN; i++){
        fact[i]=(i*fact[i-1])%mod;
    }
}

void solve(){
    // This function is called once before all queries.
    string s;
    cin>>s;
    
    int n=s.size();
    
    for(int i=1; i<=n; i++){
        int c=s[i-1]-'a';
        for(int j=0; j<26; j++){
            arr[i][j]=arr[i-1][j]+(c==j);
        }
    }
    
    compute();
    
    int q;
    while(q--){
		int l, r;
		cin>>l>>r;
		cout<<answerQuery(l, r)<<endl;
	}
}

/*
 * Complete the 'answerQuery' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER l
 *  2. INTEGER r
 */


int answerQuery(int l, int r) {
    // Return the answer for this query modulo 1000000007.
    vector<int> v(26);
    for(int i=0; i<26; i++){
        v[i]=arr[r][i]-arr[l-1][i];
    }
    
    int one=0, many=0;
    
    for(int i=0; i<26; i++){
        if(v[i]%2) one++;
        many+=v[i]/2; 
    }
    // cout<<one<<" "<<many<<endl;
    // cout<<fact[many]<<endl;
    
    int ans=fact[many];
    if(one) ans*=one;
    
    return ans%mod;
}

 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cout<<fixed<<setprecision(6);
	
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
