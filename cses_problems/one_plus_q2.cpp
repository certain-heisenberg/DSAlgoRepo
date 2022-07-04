#include <bits/stdc++.h>
using namespace std;

const int maxN=1e6+5;

int arr[maxN];
int n;

int ft[maxN];

void update(int i, int val){
    while(i<=n){
        ft[i]+=val;
        i+=i&(-i);
    }
}

int query(int i){
    int ans=INT_MIN;

    while(i>0){
        ans+=ft[i];
        i-=i & (-i);
    }

    return ans;
}

int range_query(int l, int r){
    return query(r)-query(l-1);
}

int main(){
    cin>>n;

    for(int i=1; i<=n; i++) cin>>arr[i];

    priority_queue<int> pq;

    for(int i=1; i<=n; i++){
        update(arr[i], 1);
        pq.push(arr[i]);
        int x=range_query(arr[i], n);
        if(x==n-arr[i]+1){
            while(!pq.empty()){
                int k=pq.top();
                x=range_query(k, n);
                if(x!=n-k+1) break;
                cout<<pq.top()<<" ";
                pq.pop();
            }
        }
        cout<<endl;
    }
}
