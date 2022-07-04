#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b){
	return a+rand()%(b-a+1);
}

int main(int argc, char* argv[]){
	int seed = stoi(argv[1]);
    srand(seed);
    
    int num1=rand(1,1000);
    int num2=rand(5, 100);
    
    cout<<num1<<" "<<num2<<endl;
}
