#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int bfs(int **m, int n, int startx, int starty, int endx, int endy, int distance){
    queue<vector<int>> q;
    q.push({startx, starty, 0});
    cout<<"checkpoint1";
    bool visited[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(m[i][j]==0){
                visited[i][j]=true;
            }
            else{
                visited[i][j]=false;
            }
        }
    }
    visited[startx][starty]=true;
    cout<<"checkpoint2";
    vector<int> k;
    while(!q.empty()){
        k=q.front();
        int startx=k[0];
        int starty=k[1];
        int distance=k[2];
        cout<<k[0]<<" "<<k[1]<<" "<<k[2]<<"\n";
        q.pop();
        if(startx==endx && starty==endy){
            return distance;
        }
        if(startx-1>=0 && visited[startx-1][starty]==false){
            q.push({startx-1, starty, distance+1});
            visited[startx-1][starty]=true;
        }
        if(startx+1<n && visited[startx][starty-1]==false){
            q.push({startx+1, starty, distance+1});
            visited[startx+1][starty]=true;
        }
        if(starty-1>=0 && visited[startx][starty-1]==false){
            q.push({startx, starty-1, distance+1});
            visited[startx][starty-1]=true;
        }
        if(starty+1<n && visited[startx][starty+1]==false){
            q.push({startx, starty+1, distance+1});
            visited[startx][starty+1]=true;
        }
    }
    return -1;
}

int main(){
    int n=0;
    cout<<"pls enter the size of the matrix\n";
    scanf("%d", &n);
    cout<<"pls enter the element of the matrix\n";
	int **m=(int**)malloc(n*sizeof(int*));
	for(int i=0; i<n;i++){
		m[i]=(int*)malloc(n*sizeof(int));
	}
	for(int i=0; i<n; i++){
		for(int k=0; k<n; k++){
			printf("Enter element %d%d  ", i+1,k+1);
			scanf("%d", &m[i][k]);
		}
	}
    cout<<"pls enter the start x point:\n";
    int startx=0;
    scanf("%d", &startx);
    cout<<"pls enter the start y coordinate:\n";
    int starty=0;
    scanf("%d", &starty);
    cout<<"pls enter the end coordinate:\n";
    int endx=0;
    int endy=0;
    scanf("%d", &endx);
    scanf("%d", &endy);
    int result=0;
    int distance=0;
    result=bfs(m, n, startx, starty, endx, endy, distance);
    if(result==-1){
        cout<<"path is not possible";
    }
    else{
        cout<<"the shortest path is:"<<result;
    }
    return 0;
}

