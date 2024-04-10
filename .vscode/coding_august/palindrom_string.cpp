#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std; 

bool checkpalindrome(string &s, int start, int i){
    while(start<=i){
        if(s[start++]!=s[i--]){
            return false;       
        }
    }
    return true;
}

void dfs(int start, string &s, vector<vector<string>> &result, vector<string> traverse){
    if(start==s.size()){
        result.push_back(traverse);
        return;
    }
    for(int i=start; i<s.size();i++){
        if(checkpalindrome(s, start, i)){
            traverse.push_back(s.substr(start, i-start+1));
            dfs(i+1, s, result, traverse);
            traverse.pop_back();
        }
    }
}

vector<vector<string>> partition (string &s){
    
    vector<vector<string>> result; 
    vector<vector<string>> empty;
    if(s.size()==0){
        return empty;
    }
    vector<string> traverse;
    dfs(0, s, result, traverse);

    return result;
}

int main(){
    string s;   
    cout<<"pls enter the string \n";
    cin>>s;
    vector<vector<string>> answer;
    answer={{"a","a","b"}, {"a","a","b"}};
    answer=partition(s);
    for(int k=0; k<answer.size(); k++){
        for(int f=0; f<answer[k].size(); f++){
            cout<<answer[k][f]<<" ";
        }
        cout<<"\n";
    }
}