#include <bits/stdc++.h>
using namespace std;

void computeLPS(string pat, int m, vector<int> &lps){
    int i=1, j=0;

    while(i<m){
        if(pat[j]==pat[i]){
            lps[i]=j+1;
            j++;
        }
        else{
            if(j!=0) {
                j=lps[j - 1];
            }
        }
        i++;
    }
}

vector<int> kmp(string &pat, string &s){
    int m=pat.size(), n=s.size();
 
    vector<int> lps(m, 0), indices;
 
    computeLPS(pat, m, lps);

    int i=0, j=0;

    while(i<n){
        if(pat[j]==s[i]) {
            i++, j++;
        }
        if(j==m) {
            indices.push_back(i-j);
            j=lps[j-1];
        }
        else if(i<n && pat[j]!=s[i]) {
            if (j!=0){
                j=lps[j - 1];
            }
            else{
                i++;
            }
        }
    }
    
    return indices;
}

int main(){
    string s="AABAACAADAABAABA";
    string pat="AABA";

    vector<int> indices=kmp(pat, s);

    cout<<"Pattern "<<pat<<" in text "<<s<<" found at indices: ";

    for(int c: indices){
        cout<<c<<" ";
    }
}