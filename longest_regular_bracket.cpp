#include <bits/stdc++.h>
using namespace std;

const int maxN=1000000;
int S[maxN], E[maxN], F[maxN];

int main(){
	string str;
	cin>>str;
	
	int n=str.size();
	stack<int> st;
	
	for(int i=0; i<n; i++){
		if(str[i]==')'){
			if(st.empty()) S[i]=-1;
			else{
				int k=st.top();
				st.pop();
				S[i]=k, E[i]=k;
				if(str[k-1]==')' && S[k-1]!=-1) E[i]=E[k-1];
				F[i-E[i]]++;
			}
		}
		else if(str[i]=='(') st.push(i); 
	}
	
	int len=0, count=1;
	for(int i=n-1; i>=0; i--){
		if(F[i]>0){
			len=i+1;
			count=F[i];
			break;
		}
	}
	cout<<len<<" "<<count<<endl;
}

/*
)((())))(()())
*/
