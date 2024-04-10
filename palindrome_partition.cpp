#include<stdio.h>
#include<iostream>
using namespace std;

// int check(char c[], int i, int k){
//     while(i<k){
//         if(c[i]!=c[k]){
//             return 0;
//         }
//         i++;
//         k--;
//     }
//     return 1;
// }

// int palindromepartition(char c[], int i, int n){
//     int k=n-1;
//     if(check(c, i, k) || i>=k){
//         return 0;
//     }
//     int answer=0;
//     int count=0;
//     for(int f=i; f<k; f++){
//         count=palindromepartition(c, i, f)+palindromepartition(c, f+1, k);
//         count+=1;
//         if(answer<count){
//             answer=answer;
//         }
//         else{
//             answer=count;
//         }
//     }
//     return answer;
// }

void search(){
    if(start=n){
        result.pushback();
        return;
    }
    for(int i=0; i<n; i++){
        if(check(c, start, i)=true){
            
        }
    }
}

int main(){
	int n=0;
	cout<<"pls enter amount of characters:\n";
	scanf("%d", &n);
	char c[n];
	cout<<"pls enter the characters:\n";
	for(int i=0; i<n; i++){
		scanf("%c", &c);
	}
	int result=0;
	result=palindromepartition(c, 0, n);
    cout<<"it can be devided into"<<result+1<<"strings";
    return 0;
}