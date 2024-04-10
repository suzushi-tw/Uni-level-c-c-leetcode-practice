#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;

vector<vector<int>> result;
void search(int i , int n , int k , vector<int>& temp){
    // for(int k=0; k<temp.size(); k++){
    //     cout<<temp[k];
    // }
    // cout<<"checkpoint 1\n";
    if(k == 0){
        result.push_back(temp);
        // cout<<"enter\n";
        return;
    }
    if(i == n) {
        return;
    }
    search(i + 1 , n , k , temp);
    temp.push_back(i+1);
    search(i + 1 , n , k - 1 , temp);
    temp.pop_back();
}


// vector<vector<int>> combination(int n, int k){
//     cout<<"check point 1";
//     vector<vector<int>> result;
//     vector<int> combination;
//     int temp=0;
//     while(temp>=0){
//         combination[temp]++;
//         if(combination[temp]>n){
//             temp--;
//         }
//         else if(temp=k-1){
//             result.push_back(combination);
//         }
//         else {
//             temp++;
//             combination[temp]=combination[temp-1];
//         }
//     }
//     return result;
// }

// vector<vector<int>> combinationfromsmall(int n, int k){
//     cout<<"checkpoint 1";
//     vector<vector<int>> result;
//     vector<int> temp(k,0);
//     int check=0;
//     while(check>=0){
//         temp[check]++;
//         if(temp[check]>n){
//             check--;
//         }
//         else if(check==k-1){
//             result.push_back(temp);
//         }
//         else {
//             check++;
//             temp[check]=temp[check-1];
//         }
//     }
//     return result;
// }

vector<vector<int>> combination (int n, int k){
    vector<int> ans;
    result=vector<vector<int>> (0);
    search(0, n, k , ans);
    return result;
}

int main(){
    int n=0;
    cout<<"pls enter the first integer n\n";
    cin>>n;
    int k=0;
    cout<<"pls enter the second integer k\n";
    cin>>k;
    vector<vector<int>> answer;
    answer=combination(n, k);
    for(int k=0; k<answer.size(); k++){
        for(int f=0; f<answer[k].size(); f++){
            cout<<answer[k][f]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}