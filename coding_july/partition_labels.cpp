#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> find_substring_size(string s){
    int n=s.length();
    int table[26];
    vector<int> results;
    for(int i=0; i<s.size(); i++){
        table[s[i]-'a']=i;
    }
    int max=-1;
    vector<int> difference;
    int last_character=-1;
    int last=0;
    for(int k=0; k<s.size(); k++){
        if(table[s[k]-'a']>last){
            last=table[s[k]-'a'];
        }
        if(last==k){
            results.push_back(last-last_character);
            last_character=last;
        }
    }
    return results;
}

int main(){
    string s;
    cout<<"pls enter the string:\n";
    cin>>s;
    vector<int> result;
    result=find_substring_size(s);
    cout<<"the result is:\n";
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}