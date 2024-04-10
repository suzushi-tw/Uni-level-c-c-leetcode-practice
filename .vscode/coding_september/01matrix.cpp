#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> checkadjacent(int n, int m, vector<vector<int>> mat){
    queue<pair<int,int>> temp;
    for(int f=0; f<n; f++){
        for(int l=0; l<m; l++){
            if(mat[f][l]==0){
                temp.push({l,f});
            }
            else{
                mat[f][l]=-1;
            }
        }
    }
    while(!temp.empty()){
        pair<int,int> temp2;
        temp2=temp.front();
        temp.pop();
        for(int g=0; g<4; g++){
            int dx=temp2.first-1;
            int dy=temp2.second-1;
            if(dx<0 || dy<0 || dx>=n || dy>=m ){
                continue;
            }
            mat[dx][dy]=mat[temp2.first][temp2.second]+1;
            temp.push({dx,dy});
        }
    }
    return  mat;
}

int main (){
    int n=0;
    cout<<"pls enter the number of rows";
    cin>>n;
    int m=0;
    cout<<"pls enter the number of columns";
    cin>>m;
    vector<vector<int>> mat;
    for(int i=0; i<n; i++){
        for(int k=0; k<m; k++){
            cout<<"pls enter the element"<<i<<" "<<k<<"\n";
            cin>>mat[i][k];
        }
    }
    vector<vector<int>> result;
    result=checkadjacent(n, m, mat);
    for(int f=0; f<n; f++){
        for(int j=0; j<m; j++){
            cout<<mat[f][j];
        }
    }
    return 0;
}