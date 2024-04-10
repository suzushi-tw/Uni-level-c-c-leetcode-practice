#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;

//bipartite can be devided into two sets

int graph_bipartie(int **m, int start, int n){
    int color[n];
    for(int i=0; i<n; i++){
        color[i]=-1;
    }
    color[start]=1;
    queue<int>q;
    q.push(start);
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(int nocolor=0; nocolor<n; nocolor++){
          if(m[nocolor][n]==-1){
            color[nocolor]=1-color[temp];
            q.push(n);
          }
          else if(m[nocolor][n] && color[nocolor]==color[temp]){
            return false;
          }
        }
    }
    return true;
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
    result=graph_bipartie(m, 0, n);
    if(result==true){
        cout<<"the graph is bipartie";
    }
    else if(result==false){
        cout<<"the gtaph is not bipartie";
    }
    return 0;
}