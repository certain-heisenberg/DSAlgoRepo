#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define mat vector<vector<int>>
#define vi vector<int>
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define pi pair<int, int>
#define inf 1000000000
#define mod 1000000007
#define rep(i,a,b) for(int i=a; i<=b; i++)
#define rrep(i,b,a) for(int i=b; i>=a; i--)
#define all(a) a.begin(), a.end()
 
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
char dir[4]={'D','R','U','L'};
 
//****DO NOT TOUCH ABOVE THIS LINE****//
 
const int maxN=1e5+5;

struct Data {
    int buttonAX, buttonAY;
    int buttonBX, buttonBY;
    int prizeX, prizeY;
};


void solve_part_a(std::vector<Data> dataList){
    int ans=0;
    
    for(Data d: dataList){
    	long long buttonACount = d.prizeX*d.buttonBY - d.prizeY*d.buttonBX;
    	buttonACount/=d.buttonAX*d.buttonBY - d.buttonAY*d.buttonBX;
    	
    	int buttonBCount = d.prizeX - d.buttonAX*buttonACount;
    	buttonBCount/=d.buttonBX;
    	
    	// cout<<buttonACount<<" "<<buttonBCount<<"\n";
    	
    	if(buttonACount>100 || buttonBCount > 100 || buttonACount < 0 || buttonBCount < 0){
    		continue;
    	}
    	
    	int temp1=buttonACount * d.buttonAX + buttonBCount * d.buttonBX;
    	int temp2=buttonACount * d.buttonAY + buttonBCount * d.buttonBY;
    	
    	if(temp1 != d.prizeX || temp2 != d.prizeY){
    		// cout<<temp1<<" "<<temp2<<" | ";
    		// cout<<d.prizeX<<" "<<d.prizeY<<"\n";
    		continue;
    	}
    	ans+=3*buttonACount+buttonBCount;
    }
    
    cout<<ans<<"\n";
}

void solve_part_b(std::vector<Data> dataList){
	int ans=0;
    
    for(Data d: dataList){
		d.prizeX+=10000000000000;
		d.prizeY+=10000000000000;
    	long long buttonACount = d.prizeX*d.buttonBY - d.prizeY*d.buttonBX;
    	buttonACount/=d.buttonAX*d.buttonBY - d.buttonAY*d.buttonBX;
    	
    	int buttonBCount = d.prizeX - d.buttonAX*buttonACount;
    	buttonBCount/=d.buttonBX;
    	
    	// cout<<buttonACount<<" "<<buttonBCount<<"\n";
    	
    	if(buttonACount < 0 || buttonBCount < 0){
    		continue;
    	}
    	
    	int temp1=buttonACount * d.buttonAX + buttonBCount * d.buttonBX;
    	int temp2=buttonACount * d.buttonAY + buttonBCount * d.buttonBY;
    	
    	if(temp1 != d.prizeX || temp2 != d.prizeY){
    		// cout<<temp1<<" "<<temp2<<" | ";
    		// cout<<d.prizeX<<" "<<d.prizeY<<"\n";
    		continue;
    	}
    	ans+=3*buttonACount+buttonBCount;
    }
    
    cout<<ans<<"\n";
	
}

void solve(){
	std::vector<Data> dataList; // To store all parsed data
    std::string line;

    // Read input line by line
    while (std::getline(std::cin, line)) {
        if (line.find("Button A") != std::string::npos) {
            Data data;

            // Parse Button A
            std::istringstream buttonAStream(line);
            std::string temp;
            buttonAStream >> temp >> temp >> temp; // Skip "Button A: X+"
            data.buttonAX = std::stoll(temp.substr(2)); // Extract X coordinate
            buttonAStream >> temp;                     // Read "Y+30"
            data.buttonAY = std::stoll(temp.substr(2)); // Extract Y coordinate

            // Parse Button B
            std::getline(std::cin, line); // Read the next line
            std::istringstream buttonBStream(line);
            buttonBStream >> temp >> temp >> temp; // Skip "Button B: X+"
            data.buttonBX = std::stoll(temp.substr(2)); // Extract X coordinate
            buttonBStream >> temp;                     // Read "Y+75"
            data.buttonBY = std::stoll(temp.substr(2)); // Extract Y coordinate

            // Parse Prize
            std::getline(std::cin, line); // Read the next line
            std::istringstream prizeStream(line);
            prizeStream >> temp >> temp;                 // Skip "Prize: X="
            data.prizeX = std::stoll(temp.substr(2));     // Extract X coordinate
            prizeStream >> temp;                         // Read "Y=8130"
            data.prizeY = std::stoll(temp.substr(2));     // Extract Y coordinate

            // Add the parsed data to the list
            dataList.push_back(data);
        }
    }
	solve_part_a(dataList);
	solve_part_b(dataList);
}
 
//****DO NOT TOUCH BELOW THIS LINE****//
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	cout<<fixed<<setprecision(5);
 
	#ifdef kk
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int T=1, i=1;
	// cin>>T;

	while(i<=T){
		solve();
		i++;
	}
}
