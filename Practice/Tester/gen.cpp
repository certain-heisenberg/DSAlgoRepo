#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b){
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
    int seed = stoi(argv[1]);
    srand(seed);
    
    int n = rnd(1, 5);
    cout<<n<<endl;
    
    for(int i=0;i<2*n;i++){
        int x = rand(1, 10);
        cout<<x<<" ";
    }
    cout<<endl;
}
