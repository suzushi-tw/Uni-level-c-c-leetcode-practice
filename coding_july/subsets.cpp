#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

void devide(int nums[], int start, vector<int>& current, vector<vector<int>>& result, int n){
    result.push_back(current);
    for(int i=start; i<n; i++){
        current.push_back(nums[i]);
        devide(nums, i+1, current, result, n);
        current.pop_back();
    }
}

vector<vector<int>>find_subsets(int nums[], int n){
    cout<<"point 2\n";
    vector<vector<int>>result;
    vector<int>current;
    devide(nums, 0, current, result, n);
    cout<<"point 3\n";
    return result;
}

int main(){
    int n=0;
    cout<<"pls enter the amount of numbers:\n";
    scanf("%d", &n);
    int nums[n];
    cout<<"pls enter the number:\n";
    for(int i=0; i<n; i++){
        scanf("%d", &nums[i]);
    }
    vector<vector<int>> results;
    cout<<"point 1\n";
    results=find_subsets(nums, n);
    for(int i=0; i<results.size(); i++){
        for(int k=0; k<results[i].size(); k++){
            cout<<results[i][k]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}