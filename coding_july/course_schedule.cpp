#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

bool check_schedule(){
    
}

int main(){
    int numcourses=0;
    cout<<"pls enter the number of courses you have to take:\n";
    scanf("%d", &numcourses);
    vector<pair<int, int>> prerequisites;
    for(int i=0; i<numcourses; i++){
        int ai=0;
        cout<<"pls enter the previous course:\n";
        scanf("%d", &ai);
        int bi=0;
        cout<<"pls enter the course following it:\n";
        scanf("%d", &bi);
        prerequisites.push_back({ai, bi});
    }
}