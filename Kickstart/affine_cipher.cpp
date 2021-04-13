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

	string s="lfkpxivwfcravcghkdyklfiljxczmdkegiuelckvesxklfkwcvrmdkvlmihmlucrokeeiykelfilgkekvdlfkmvlkyxmlucrdililfilgkelcxkivdislfkvlmwilkewcvlkvlivdecsxwkcrwcoosvmwilmcvelfilgkxkwkmzkmeeimdlcpkwxujlcyxijfu";
	
	for(int a=1; a<mod; a++){
		if(__gcd(a, mod)==1){
			int a_inverse=findInverse(a); // Brute force method to find inverse
			
			for(int b=1; b<mod; b++){
				for(int i=0; i<(int)s.size(); i++){
					int d=(((s[i]-'a')-b)%mod+mod)%mod;
					d=(d*a_inverse)%mod;
					cout<<char(d+'a');
				}
				
				cout<<"\n\n";
			}
		}
	}
	
	//Line 165 in the output is the meaningful answer
}
