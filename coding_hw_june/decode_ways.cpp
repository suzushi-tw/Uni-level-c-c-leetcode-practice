#include<stdio.h>
#include<iostream>
using namespace std;

int waystoencode(string s[], int start, int n){
    if(start==n){
        return 1;
    }
    if(s[0]=='0'){
        return 0;
    }
    int solution=0;
    int tenth=0;
    int one=0;
    solution=waystoencode(s, start+1, n);
    int solution2=0;
    if(start<n-1){
        tenth=(s[start]-'0')*10;
        one=s[start+1]-'0';
        if(tenth+one<=26){
            solution2=waystoencode(s, start+2, n);
        }
    }
    return solution+solution2;
}

int main(){
    cout<<"pls enter the size of the string:\n";
    int n=0;
    scanf("%d", &n);
    string s[n];
    scanf("%s", &s);
    int start=0;
    int result=0;
    result=waystoencode(s, 0, n);
    cout<<"the number of ways to encode are:"<<result;
    return 0;
}