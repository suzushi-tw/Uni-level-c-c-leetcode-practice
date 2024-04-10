#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

vector<pair<int,int>> findpair(int **m, int r, int c){
    vector<int> sumr;
    vector<int> sumc;
    vector<pair<int,int>> answer_to_return;
    for(int i=0; i<r; i++){
        int temp=0;
        for(int k=0; k<c; k++){
            temp+=m[i][k];
        }
        sumr[i]=temp;
    }
    for(int f=0; f<r; f++){
        int temp1=0;
        for(int l=0; f<c; f++){
            temp1+=m[f][l];
        }
        sumc[f]=temp1;
    }
    for(int n=0; n<r; n++){
        for(int g=n; g<c; g++){
            if(sumr[n]==sumc[g]){
                answer_to_return.push_back({sumr[n], sumc[g]});
            }
        }
    }
    if(answer_to_return.size()==0){
        cout<<"there's no matching pairs\n";
    }
    return answer_to_return;
}

int main(){
    int r=0;
    cout<<"pls enter number of rows:\n";
    scanf("%d", &r);
    cout<<"pls enter number of columns:\n";
    int c=0;
    scanf("d", &c);
    cout<<"pls enter the element of the matrix\n";
	int **m=(int**)malloc(r*sizeof(int*));
	for(int i=0; i<r;i++){
		m[i]=(int*)malloc(c*sizeof(int));
	}
	for(int i=0; i<r; i++){
		for(int k=0; k<c; k++){
			printf("Enter element %d%d  ", i+1,k+1);
			scanf("%d", &m[i][k]);
            fflush(stdin);
		}
    }
    vector<pair<int,int>> result;
    result=findpair(m, r, c);
    for(int i=0; i<result.size(); i++){
        cout<<result[i].first<<" "<<result[i].second;
    }
    return 0;
}