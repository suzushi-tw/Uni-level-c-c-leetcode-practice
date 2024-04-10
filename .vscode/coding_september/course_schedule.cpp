#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool check_request(int numCourses, vector<vector<int>> prerequisites){
    vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> in(numCourses);
        for (auto a : prerequisites) {
            graph[a[1]].push_back(a[0]);
            ++in[a[0]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] == 0) q.push(i);
        }
        for(int k=0; k<q.size(); k++){
            int temp=q.front();
            q.pop();
            cout<<temp<<" ";
            q.push(temp);
        }
        while (!q.empty()) {
            int t = q.front(); q.pop();
            for (auto a : graph[t]) {
                --in[a];
                if (in[a] == 0) q.push(a);
            }
        }
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] != 0) return false;
        }
        return true;
}

int main(){
    int n=0;
    cout<<"pls enter the number of sets for prerequisties\n";
    cin>>n;
    vector<vector<int>> prerequisties;
    vector<int> temp(0);
    for(int i=0; i<n; i++){
        int num1=0;
        int num2=0;
        cin>>num1;
        cin>>num2;
        temp.push_back(num1);
        temp.push_back(num2);
        prerequisties.push_back(temp);
        temp.pop_back();
        temp.pop_back();
    }
    for(int k=0; k<prerequisties.size(); k++){
        for(int f=0; f<prerequisties[k].size(); f++){
            cout<<prerequisties[k][f];
        }
        cout<<"\n";
    }
    int numCourses=0;
    cout<<"pls enter the number of courses you have to take \n";
    cin>>numCourses;
    bool answer;
    answer=check_request(numCourses, prerequisties);
    if(answer==true){
        cout<<"the prerequesities has no conflict";
    }
    else{
        cout<<"false, there's problem in the time table";
    } 
    return 0;
}