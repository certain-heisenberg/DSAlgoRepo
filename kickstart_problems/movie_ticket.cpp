#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vs vector<string>
#define mat vector< vi >  

map<string, mat> screen;
map<string, set<int> > mp;

void add_screen(vs &v){

    if(mp.find(v[1])!=mp.end()){
        cout<<"failure"<<endl;
        return;
    }

    for(int i=4; i<v.size(); i++){
        mp[v[1]].insert(stoi(v[i])-1);
    }

    int row=stoi(v[2]);
    int col=stoi(v[3]);

    mat hall(row, vector<int> (col, 0));
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(mp[v[1]].find(j)!=mp[v[1]].end()) hall[i][j]=2;
        }
    }

    screen[v[1]]=hall;

    cout<<"success"<<endl;
}

void reserve(vs &v){
    if(mp.find(v[1])==mp.end()){
        cout<<"failure"<<endl;
        return;
    }

    int row=stoi(v[2])-1;

    vector<int> seats;
    for(int i=3; i<v.size(); i++){
        seats.push_back(stoi(v[i])-1);
    }

    mat hall=screen[v[1]];

    for(int i=0; i<seats.size(); i++){
        if(hall[row][seats[i]]==1 || hall[row][seats[i]]==3){
            cout<<"failure"<<endl;
            return;
        }
    }

    for(int i=0; i<seats.size(); i++){
        if(hall[row][seats[i]]==0) hall[row][seats[i]]=1;
        else if(hall[row][seats[i]]==2) hall[row][seats[i]]=3;
    }

    screen[v[1]]=hall;
    
    cout<<"success"<<endl;
}

void get_seats(vs &v){
    if(mp.find(v[1])==mp.end()){
        cout<<"failure"<<endl;
        return;
    }

    int row=stoi(v[2])-1;

    mat hall=screen[v[1]];

    for(int i=0; i<hall[row].size(); i++){
        if(hall[row][i]==0 || hall[row][i]==2) cout<<i+1<<" ";
    }
    cout<<endl;
}

void suggest(vs &v){
    if(mp.find(v[1])==mp.end()){
        cout<<"none"<<endl;
        return;
    }

    mat hall=screen[v[1]];

    int num=stoi(v[2]);
    int row=stoi(v[3])-1;
    int choice=stoi(v[4])-1;

    int len=hall[0].size();
    int f1=0, f2=0;
    
    //for(int i=0; i<len; i++) cout<<hall[row][i]<<" ";
    
    if(choice-num+1>=0){
        for(int i=choice; i>=choice-num+1; i--){
            if(hall[row][i]==1 || hall[row][i]==3){
                f1=1;
                break;
            }
            else if(hall[row][i]==2 && i!=choice-num+1 && i!=choice){
				f1=1;
				break;
			}
        }
    }
    else f1=1;
    
    if(f1==0){
		for(int i=choice-num+1; i<=choice; i++){
			cout<<i+1<<" ";
		}
		cout<<endl;
		return;
	}

    if(choice+num<=len){
        for(int i=choice; i<choice+num; i++){
            if(hall[row][i]==1 || hall[row][i]==3){
                f2=1;
                break;
            }
            else if(hall[row][i]==2 && i!=choice+num-1 && i!=choice){
				f2=1;
				break;
			}
        }
    }
    else f2=1;

    if(f2==0){
		for(int i=choice; i<choice+num; i++){
			cout<<i+1<<" ";
		}
		cout<<endl;
		return;
	}
	
	cout<<"none"<<endl;
}

int main(){
    int t;
    cin>>t;
    cin.ignore();

    while(t--){
        string s;
        getline(cin, s);
        stringstream X(s);

        vector<string> v;
        string temp;

        while(getline(X, temp, ' ')){
            v.push_back(temp);
        }
        
        if(v[0]=="add-screen"){
            add_screen(v);
        }
        else if(v[0]=="reserve-seat"){
            reserve(v);
        }
        else if(v[0]=="get-unreserved-seats"){
            get_seats(v);
        }
        else if(v[0]=="suggest-contiguous-seats"){
            suggest(v);
        }
        else{
            cout<<"failure"<<endl;
        }
        //if(t==2) break;
    }
}
