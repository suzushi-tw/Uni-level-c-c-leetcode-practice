#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;


int countoptimal(int **m, int r, int c){
    int i=0;
    int j=c-1;
    int solution=0;
    while( i<r && j>=0){
        int current=m[i][j];
        if(current<0){
            solution+=r-i;
            j--;
        }
        else{
            i++;
        }
    }
    return solution;
}

// int countiterate(int **m, int r, int c){
//     int count=0;
//     for(int i=0; i<r; i++){
//         for(int k=0; k<c; k++){
//             if(m[i][k]<0){
//                 count+=1;
//             }
//             else{
//                 break;
//             }
//         }
//     }
//     return count;
// }

int main(){
    int r=0;
    cout<<"pls enter number of rows:\n";
    scanf("%d", &r);
    int c=0;
    cout<<"pls enter number of columns:\n";
    scanf("%d", &c);
    cout<<"pls enter the element of the matrix\n";
	int **m=(int**)malloc(r*sizeof(int*));
	for(int i=0; i<r;i++){
		m[i]=(int*)malloc(c*sizeof(int));
	}
	for(int i=0; i<r; i++){
		for(int k=0; k<c; k++){
			printf("Enter element %d%d  ", i+1,k+1);
			scanf("%d", &m[i][k]);
		}
	}
	//int result=0;
    int result1=0;
	//result=countiterate(m, r, c);
    result1=countoptimal(m, r, c);
	//cout<<"amount of negative number is:"<<result;
    cout<<"amount of negative number using a more optimal solution is:"<<result1;
	return 0;
}