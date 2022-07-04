#include <bits/stdc++.h>
using namespace std;

int main(){
	cout<<"Please enter the binary message bit:"<<endl;
	
	string s;
	cin>>s;
	
	int m=s.size(); // size of message bit
	
	int parityBitCount=0; // number of required parity bits
	
	while(pow(2, parityBitCount)<m+parityBitCount+1){
		parityBitCount++;
	}
	
	int n=m+parityBitCount; // size of hamming code
	bool arr[n+1];
	
	int p=0, q=0;
	
	for(int i=1; i<=n; i++){
		if(pow(2, p)==i) arr[i]=0, p++;
		else arr[i]=s[q]-'0', q++;
	}

	cout<<"\nHamming code of the given message bit "<<s<<" is: ";
	
	// Method 1::
	
	for(int i=0; i<parityBitCount; i++){
		int parityBitIndex=pow(2, i);
		int bitsToCheck=parityBitIndex;
		int countOfOnes=0;
		
		for(int j=parityBitIndex; j<=n; j+=2*bitsToCheck){
			int l=j;
			while(l<j+bitsToCheck && l<=n){
				if(l!=i && arr[l]) countOfOnes++;
				l++;
			}
		}
		if(countOfOnes%2) arr[parityBitIndex]=1;	
	}
	
	// Method 2::
	
	//for(int i=0; i<parityBitCount; i++){
		//int parityBitIndex=pow(2, i);
		//int countOfOnes=0;
		//for(int j=i+1; j<=n; j++){
			//if(((j>>i) & 1) && arr[j]) countOfOnes++;
		//}
		//if(countOfOnes%2) arr[parityBitIndex]=1;
	//}
	
	for(int i=1; i<=n; i++) cout<<arr[i];
	
	cout<<"\nTotal number of parity bits required is: "<<parityBitCount;
}
