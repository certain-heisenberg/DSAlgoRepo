#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

ll res;

void merge(vector<int> &arr, int l, int mid, int r){
    int total = arr.size();
    int n=mid-l+1;
    int m=total-n;
    
    vector<int> left(n, 0);
    vector<int> right(m, 0);
    
    for(int i=0; i<n; i++) left[i]=arr[l+i];
    
    for(int i=0; i<m; i++) right[i]=arr[mid+1+i];
    
    int a=0, b=0;
    int c=l; // starting index in the merged segment
        
    while(a<n && b<m){
        if(left[a]<=right[b]){
            arr[c]=left[a];
            a++;
            c++;
        }
        else{
            arr[c]=right[b];
            b++;
            c++;
            res+=(n-a);
        }
    }
    
    while(a<n){
        arr[c]=left[a];
        a++;
        c++;
    }
    
    while(b<m){
        arr[c]=right[b];
        b++;
        c++;
    }
}

void mergesort(vector<int> &arr, int l, int r){
    if(l>=r) return;
    
    int mid=(l+r)/2;
    
    mergesort(arr, l, mid);
    mergesort(arr, mid+1, r);
    merge(arr, l, mid, r);
}

void solve(){
    int n;
    cin>>n;
    
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    res=0;
    mergesort(arr, 0, n-1);
    
    //for(int c: arr) cout<<c<<" ";
    
    cout<<res<<endl;
}

signed main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
}

/*
2  
5  
1 1 1 2 2  
5  
2 1 3 1 2
*/
