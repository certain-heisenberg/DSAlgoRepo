#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin>>T;
	
	while(T--){
		int A;
		cin>>A;

		queue<int > q;
		q.push(1);
		
		vector<bool> visited(A);
		vector<int> parent(A);
		vector<bool> digit(A);
		visited[1]=true;
		parent[1]=-1;
		digit[1]=true;
		
		while(!q.empty()){
			int temp=q.front();
			q.pop();
			if(temp==0) break;
			
			int mod0=(temp*10)%A;
			int mod1=(temp*10+1)%A;
			
			if(visited[mod0]==false){
				visited[mod0]=true;
				parent[mod0]=temp;
				digit[mod0]=false;
				q.push(mod0);
			}
			if(visited[mod1]==false){
				visited[mod1]=true;
				parent[mod1]=temp;
				digit[mod1]=true;
				q.push(mod1);
			}
		}
		
		string ans="";
		int i=0;
		while(i != -1){
			ans+=digit[i]+'0';
			i=parent[i];
		}
		
		reverse(ans.begin(),ans.end());
		cout<<ans<<endl;
	}
}


/*
3
17
11011
17
*/
