#include <bits/stdc++.h>
using namespace std;
 
#define kk
#define endl "\n"

void solve(){
	srand((unsigned) time(0));

    int res1 = 1 + (rand() % 6); // generates random no. between 1 and 6(including 1 & 6)
    
    float res2 =((float) rand()) / RAND_MAX; // generates random no. between 0 and 1(excluding 0 & 1) 
	
	cout<<res1<<endl<<res2<<endl;
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
