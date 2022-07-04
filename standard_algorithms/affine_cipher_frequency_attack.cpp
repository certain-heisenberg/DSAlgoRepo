#include <bits/stdc++.h>
using namespace std;

// Brute force implementation of deciphering "cipher text" encrypted
// using "Affine Cipher" on English alphabets of 26 letters by iterating over all
// possible keys in "Affine Cipher".

// Encryption function: e(x) = (a*x+b) mod 26 
// Decryption function: d(y) = a^(-1)*(y-b) mod 26
// where a, b belongs to {1,2,...,25}

// Here Affine Cipher has 12*25=300 total possible keys.

#define mod 26

int findInverse(int a){
	int ans=1;
	
	for(int i=1; i<mod; i++){
		if((i*a)%mod==1){
			ans=i;
			break;
		}
	}
	
	return ans;
}

int main(){
	
	//freopen("output.txt", "w", stdout); // Uncomment this line to see the output in "output.txt"

	string s="FMXVEDKAPHFERBNDKRXRSREFMORUDSDKDVSHVUFEDKAPRKDLYEVLRHHRH";
	
	map<char, int> mp;
	
	for(auto c: s) mp[c]++;
	
	int sum=0;
	
	for(auto c: mp) cout<<c.first<<" "<<c.second<<"\n", sum+=c.second;
	
	cout<<sum<<endl;
}
