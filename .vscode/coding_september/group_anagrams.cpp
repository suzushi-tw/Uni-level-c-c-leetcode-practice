#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> strs) {
    vector<vector<string>> result;
    map<string, vector<string>> mp;
    for(int i=0; i<strs.size(); i++){
        string temp=strs[i];
        sort(temp.begin(), temp.end());
        // mp[strs[i]].push_back(temp);
        mp[temp].push_back(strs[i]);
    }
    for (map<string, vector<string>>::iterator it=mp.begin(); it!=mp.end(); ++it){
        result.push_back(it->second);
    }
    return result;
}

int main(){
    int n=0;
    cout<<"pls enter amount of strings";
    cin>>n;
    vector<string> str;
    string temp;
    cout<<"pls enter the string";
    for(int i=0; i<n; i++){
        cin>>temp;
        str.push_back(temp);
    }
    vector<vector<string>> answer;
    cout<<"\n";
    answer=groupAnagrams(str);
    for(int i=0; i<answer.size(); i++){
        for(int f=0; f<answer[i].size(); f++){
            cout<<answer[i][f]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
