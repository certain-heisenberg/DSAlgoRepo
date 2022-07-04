#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define mat vector<vector<int>>
#define vi vector<int>
#define ff first
#define ss second
#define mod 1000000007

//****DO NOT TOUCH ABOVE THIS LINE****//

mat mul(mat A, mat B){
	mat res={{0,0},
			 {0,0}};
			 
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			for(int k=0; k<2; k++){
				res[i][j]+=A[i][k]*B[k][j];
			}
		}
	}
	
	return res;
}

mat power(mat A, int n){
	mat res={{1,0},
			 {0,1}};
			 
	while(n){
		if(n%2) res=mul(res, A), n--;
		else A=mul(A, A), n/=2;
	}
	
	return res;
}

//#define kk

const int maxN=1e5+5;

void solve(){
	mat A={{0, 1},
		   {1, 1}};
	
	/*
	 Matrix A is known as "Magic Matrix"
	 
	 Magic Matrix is obtained using the relation between "Recurrence Relation" and "Magic Matrix".
	 The relation between them is stated as follows:
	 
	 [F1 F2] * [A B]^(n-1) = [Fn Fn+1]   
               [C D]
                
     Fi represents ith term in the recurrence relation.          
	 
	 Thus, F1*A+F2*C=F2 and F1*B+F2*D=F3
	 
	 If "Recurrence Relation" is know or more specifically if first 3 terms of "Recurrence Relation"
	 is known then we can easily find the "Magic Matrix" using which we can find F(n), the nth number
	 in the recurrence relation, as shown below.
	 	
	*/
	int n;
	cin>>n;
		   
	// Calculation of F(n):-
	
	// If we are finding F(n) then value of exponent in below expression should be n-1
	mat res=power(A, n-1);
	
	//cout<<res[0][0]<<" "<<res[0][1]<<"\n"<<res[1][0]<<" "<<res[1][1]<<endl;
	
	// The value obtained after multiplying row matrix [F1 F2] with 1st column of magic matrix
	// is the value of F(n)
	
	int Fn=2*res[0][0]+2*res[1][0]; // F(n)
	
	cout<<Fn<<endl;
	
	// Calculation of Fibonacci Series:
	
	// Below is the expression specific to Fibonacci Series only
	// F(n+2) - F(2) = F(1)+F(2)+F(3)+......+F(n)
	
	// Thus for finding sum of first "n" fibonacci numbers we will calculate F(n+2)
	// And subtract F(2) from it
	
	cin>>n;
	
	res=power(A, n+1);
	int fibNSum=2*res[0][0]+2*res[1][0]; // F(n+2)
	
	fibNSum-=2; // subtracting F(2) from F(n+2)
	
	cout<<fibNSum<<endl<<endl;
}

//****DO NOT TOUCH BELOW THIS LINE****//

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cout<<fixed<<setprecision(18);

	#ifdef kk
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#endif
		
	int T=1;
	cin>>T;

	while(T--){		
		solve();
	}
}

void query(){ // Problem asked in Instabase intern test / Alphonso DS test
	int q;
	cin>>q;
	
	mat A={{0, 1},
		   {1, 1}};
	
	int l, r;
	cin>>l>>r;
	
	mat res=power(A, r+1);
	int sum1=2*res[0][0]+2*res[1][0];
	sum1-=2;
	
	res=power(A, l);
	int sum2=2*res[0][0]+2*res[1][0];
	sum2-=2;
	
	sum1-=sum2;
	
	cout<<sum1%10<<endl;
}
