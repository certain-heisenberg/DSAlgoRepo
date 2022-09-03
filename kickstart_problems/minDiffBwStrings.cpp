#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Problem Statement:

Given two strings of uppercase letters source and target, list (in string form) a sequence of edits to convert from source to target that uses the least edits possible.
For example, with strings source = "ABCDEFG", and target = "ABDFFGH" we might return: ["A", "B", "-C", "D", "-E", "F", "+F", "G", "+H"]
*/

// M1: Printing string answer directly using rescurise call then using dp table
// This will have very large space complexity

vector<vector<string>> dp;

string solve(const string& s, const string& t, int i, int j){
  if(i==s.size() && j==t.size()) return "";
  
  if(i==s.size()){
    string val="";
    for(int l=j; l<t.size(); l++){
      string x(1,t[l]);
      val+="+"+x+" ";
    }
    return val;
  }
  
  if(j==t.size()){
    string val="";
    for(int l=i; l<s.size(); l++){
      string x(1,s[i]);
      val+="-"+x+" ";
    }
    return val;
  }
  
  if(dp[i][j]!="-1") return dp[i][j];
  
  if(s[i]==t[j]){
    string x(1, s[i]);
    return dp[i][j]=x+" "+solve(s, t, i+1, j+1);
  }
  else{
    string ans1=solve(s, t, i+1, j);
    string ans2=solve(s, t, i, j+1);
    string x(1, s[i]), y(1, t[j]);
   
    if(ans1.size()<=ans2.size()){
      return dp[i][j]="-"+x+" "+ans1;
    }
    else{
      return dp[i][j]="+"+y+" "+ans2;
    }
  }
}

vector<string> diffBetweenTwoStrings(const string& s, const string& t)
{
  dp.clear();
  dp.resize(1000, vector<string> (1000, "-1"));
  string res=solve(s, t, 0, 0);
  
  vector<string> ans;
  string temp="";
  
  for(int i=0; i<res.size(); i++){
    if(res[i]==' '){
      ans.push_back(temp);
      temp="";
    }
    else{
      temp.push_back(res[i]);
    }
  }
  
  return ans;
}

/*****************************OTHER  APPROACH************************************************/

// M2: First fill the dp table with optimal answers, then construct answer string using this table

vector<vector<int>> dp2;

int solve2(const string& s, const string& t, int i, int j){
  if(i==s.size() && j==t.size()) return dp2[i][j]=0;
  if(i==s.size()) return dp2[i][j]=t.size()-j;
  if(j==t.size()) return dp2[i][j]=s.size()-i;
  
  if(dp2[i][j]!=-1) return dp2[i][j];
  
  if(s[i]==t[j]){
    return dp2[i][j]=solve2(s, t, i+1, j+1);
  }
  else{
    int ans1=solve2(s, t, i+1, j);
    int ans2=solve2(s, t, i, j+1);
    
    return dp2[i][j]=min(ans1,ans2)+1;   
  }
}

void getAns(vector<string> &ans, const string& s, const string& t){
  int i=0, j=0;
  
  while(i<s.size() && j<t.size()){
    if(s[i]==t[j]){
      ans.push_back(string(1,s[i]));
      i++, j++;
    }
    else{
      if(dp2[i+1][j]<=dp2[i][j+1]){
        ans.push_back("-"+string(1,s[i]));
        i++;
      }
      else{
        ans.push_back("+"+string(1,t[j]));
        j++;
      }
    }
  }
  
  while(i<s.size()){
    ans.push_back("-"+string(1,s[i]));
    i++;
  }
  
  while(j<t.size()){
    ans.push_back("+"+string(1,t[j]));
    j++;
  }
}

vector<string> diffBetweenTwoStrings2(const string& s, const string& t)
{
  dp2.clear();
  dp2.resize(100, vector<int> (100, -1));
  int res=solve2(s, t, 0, 0);
  cout<<"Total edits: "<<res<<"\n";
  
  vector<string> ans;
  getAns(ans, s, t);
  return ans;
}

int main() 
{
  string s="ABCDEFG", t="ABDFFGH";
  
  vector<string> ans=diffBetweenTwoStrings2(s, t);
  for(auto c: ans){
    cout<<c<<" ";
  }
}
