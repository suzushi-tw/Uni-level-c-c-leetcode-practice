#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// bool checkpath(int **m, int x, int y, int N, int **visited){
//     if(x>=0 && x<N && y>=0 && y<N && m[x][y]==1 && visited[x][y]==false){
//         return true;
//     }
//     return false;
// }

int shortest_path(int **m, int N, int startx, int starty, int endx, int endy, int **visited){
    queue<vector<int>> q;
    q.push({startx, starty, 0});
    vector<int> temp;
    while(!q.empty()){
        temp=q.front();
        int x=temp[0];
        int y=temp[1];
        int distance=temp[2];
        q.pop();
        cout<<x<<" "<<y<<" "<<distance<<"\n";
        if(x==endx && y==endy){
            return distance;
        }
        if(x-1>=0 && visited[x-1][y]==0){
            q.push({x-1, y, distance+1});
            visited[x-1][y]=true;
        }
        if(x+1<N && visited[x+1][y]==0){
            q.push({x+1, y, distance+1});
            visited[x+1][y]=true;
         }
        if(y-1>=0 && visited[x][y-1]==0){
            q.push({x, y-1, distance+1});
            visited[x][y-1]=true;
        }
        if(y+1<N && visited[x][y+1]==0){
            q.push({x, y+1, distance+1});
            visited[x][y+1]=true;
        }
        if (x-1>=0 && y+1 <N && visited[x-1][y+1]==0){
            q.push({x-1, y+1, distance+1});
            visited[x-1][y+1]=true;
        }
        if(x+1<N && y+1<N && visited[x+1][y+1]==0){
            q.push({x+1, y+1, distance+1});
            visited[x+1][y+1]=true;
        }
        if(x-1>=0 && y-1>=0 && visited[x-1][y-1]==0){
            q.push({x-1, y-1, distance+1});
            visited[x-1][y-1]=true;
        }
        if(x+1<N && y-1>=0 && visited[x+1][y-1]==0){
            q.push({x+1, y-1, distance+1});
            visited[x+1][y-1]=true;
        }
    }
    return -1;
}

int main(){
    int n=0;
    cout<<"ple enter the size of matrix:\n";
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
    int result=0;
    int startx=0;
    int starty=0;
    int endx=n-1;
    int endy=n-1;
    int **visited;
    visited= new int *[n];
    for(int k=0; k<n; k++){
        visited[k]=new int [n];
    }
    for(int l=0; l<n; l++){
        for(int f=0; f<n; f++){
            if(m[l][f]==0){
                visited[l][f]=0;
            }
            else{
                visited[l][f]=1;
            }
        }
    }
//      int **array;
//      array = new int *[10];
//      for(int i = 0; i <10; i++)
//      array[i] = new int[10];
    result=shortest_path(m, n, startx, starty, endx, endy, visited);
    cout<<"the shortest path of matrix from top left to bottom right is:"<<result;
    return 0;
}