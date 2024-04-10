#include<stdio.h>
#include<iostream>
using namespace std;
#include<vector>

// int findRoot(vector<int>& parent, int node) {
//     cout<<"checkpoint 2\n";
//     if (parent[node] == -1){
//         return node;
//     }
//     return findRoot(parent, parent[node]);
// }

// bool checktree(int n, vector<pair<int,int>>& input){
//     cout<<"check point 1\n";
//     vector<int> parent(n);
//     for(int k=0; k<n; k++){
//         parent[k]=-1;
//     }
//     for (int f; f<input.size();f++) {
//         int root1 = findRoot(parent, input[f].first);
//         int root2 = findRoot(parent, input[f].second);
//         if (root1 == root2){
//             return false;
//         }
//         parent[root1] = root2;
//     }
//     int count = 0;
//     for (int i = 0; i < n; i++) {
//         if (parent[i] == -1) count++;
//     }
// }

void dfs(vector<vector<int>> &graph, vector<bool> &v, int k){
    v[k]=true;
    for(int i=0; i<graph[k].size(); i++){
        // cout<<i<<" "<<k<<"\n";
        if(v[graph[k][i]]==false){
            dfs(graph, v, graph[k][i]);
        }
    }
}

bool validtree(int n, vector<pair<int,int>> &input, int n_pair){
    vector<vector<int>> graph(n);
    for(int i=0; i<n_pair; i++){
        graph[input[i].first].push_back(input[i].second);
        graph[input[i].second].push_back(input[i].first);
    }
    vector<bool> v(n, false);
    dfs(graph, v, 0);
    int count=0;
    for(int f=0; f<v.size(); f++){
        if(v[f]){
            count++;
        }
    }
    if(count==n && n_pair==n-1){
        return true;
    }
    return false;
}

int main(){
    int n=0;
    cout<<"pls enter the number of nodes\n";
    scanf("%d", &n);
    int n_pair=0;
    cout<<"pls enter the number of paris for the input";
    scanf("%d", &n_pair);
    vector<pair<int,int>> input(n_pair,{0, 0});
    int temp1=0;
    int temp2=0;
    for(int i=0; i<n_pair; i++){
        cout<<"pls enter the number for"<<i<<"th pairs \n";
        cin>>temp1;
        input[i].first=temp1;
        cin>>temp2;
        input[i].second=temp2;
    }
    bool result;
    result=validtree(n ,input, n_pair);
    cout<<result;
    return 0;
}