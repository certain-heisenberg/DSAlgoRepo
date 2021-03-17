#include <bits/stdc++.h>
using namespace std;

int cnt[1000001];

int main() {
    int n;
    cin>>n;
    while(n--){
        int k;
        cin>>k;
        cout<<cnt[k]<<endl;
        for(int i=1; i<=sqrt(k); i++){
            if(k%i==0){
                cnt[i]++;
                if(i*i!=k) cnt[k/i]++;
            }
        }
        for(int i=1; i<=k; i++){
			cout<<cnt[i]<<" ";
		}
		cout<<endl;
    }
    return 0;
}

//7
//8 1 28 4 2 6 7
