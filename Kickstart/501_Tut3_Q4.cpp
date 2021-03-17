//Name: David Gokimmung
//Enrolment No: 17114023

#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> ar = {
    {'A','C','D','F','G'},
    {'D','G','H','L'},
    {'B','E','I','K','M'},
    {'A','B','R','S','U'},
    {'C','F','J','L','N'},
    {'H','N','O','P','Q'},
    {'R','U','X','Y'},
    {'B','J','P','W'},
    {'A','F','K'},
    {'T','V','X','Y'},
    {'B','D','F','H'},
    {'A','L','F','Q'}
};

multiset<char> rem = {'A','A','B','B','C','D','E',  //campus areas A and B are for chiefguests resting room’s security, so these two areas require at least two cameras each
                    'F','G','H','I','J','K','L','M',
                    'N','O','P','Q','R','S','T','U',
                    'V','W','X','Y'};

vector<int> cost(12);

int main(){
    vector<int> ans;

    //Camera location 7 gives a perfect shot for the main gate, so it must install the camera here.
    ans.push_back(7);
    for(char c:ar[6]){
        rem.erase(rem.find(c));
    }

    while(!rem.empty()){
        for(int i=0;i<12;i++){
            int x = 0;
            for(char c:ar[i]){
                if(rem.find(c)!=rem.end()) x++;
            }
            cost[i] = x;
        }
        int j = max_element(cost.begin(),cost.end()) - cost.begin();
        ans.push_back(j+1);
        for(char c:ar[j]){
            if(rem.find(c)!=rem.end()) rem.erase(rem.find(c));
        }
    }

    cout<<"Minimum number of cameras needed : "<<ans.size()<<endl;
    
    sort(ans.begin(),ans.end());
    cout<<"Camera Locations : ";
    for(int i:ans){
        cout<<i<<' ';
    }
    cout<<endl;

    return 0;
}