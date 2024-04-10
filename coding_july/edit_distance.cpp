#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int distancedp(string s1, string s2, int length1, int length2){
    int dp[length1+1][length2+1];
    for(int i=0; i<length1+1; i++){
        dp[i][0]=i;
    }
    for(int k=0; k<length2+1; k++){
        dp[0][k]=k;
    }
    for(int f=1; f<length1+1; f++){
        for(int j=1; j<length2+1; j++){

            if(s1[f-1]==s2[j-1]){
                dp[f][j]=dp[f-1][j-1];
            }
            else{
                if(dp[f-1][j-1]<=dp[f-1][j] && dp[f-1][j-1]<=dp[f][j-1]){
                    dp[f][j]=dp[f-1][j-1]+1;
                }
                else if(dp[f-1][j]<=dp[f-1][j-1] && dp[f-1][j]<=dp[f][j-1]){
                    dp[f][j]=dp[f-1][j]+1;
                }
                else{
                    dp[f][j]=dp[f][j-1]+1;
                }
            }
            cout<<f<<" "<<j<<"\n";
        }
    }
    for(int i=0; i<length1+1; i++){
        for(int k=0; k<length2+1; k++){
            cout<<dp[i][k]<<" ";
        }
        cout<<"\n";
    }
    return dp[length1][length2];
}

int distance(string s1, string s2, int length1, int length2){
    if(length1==0){
        return length2;
    }
    if(length2==0){
        return length1;
    }
    if(s1[length1-1]==s2[length2-1]){
        return distance( s1, s2, length1-1, length2-1);
    }
    else{
        int remove=distance(s1, s2, length1, length2-1);
        int insert=distance(s1, s2, length1-1, length2);
        int replace=distance(s1, s2, length1-1, length2-1);
        int result=0;
        if(remove<insert){
            result=remove;
            if(result>replace){
                result=replace;
            }
        }
        else{
            result=insert;
            if(result>replace){
                result=replace;
            }
        }
        return result+1;
    }
}

int check(string s1, string s2, int length1, int length2){
    if(length1==0){
        return length2;
    }
    if(length2==0){
        return length1;
    }
    else{
        return distance(s1, s2, length1, length2);
    }
}

int main(){
    cout<<"pls enter te first string:\n";
    string s1;
    cin>>s1;
    cout<<"pls enter the second string:\n";
    string s2;
    cin>>s2;
    int length1=s1.size();
    int length2=s2.size();
    int result=0;
    result=check(s1, s2, length1, length2);
    int result2=0;
    result2=distancedp(s1, s2, length1, length2);
    cout<<"the number of operation is:\n"<<result<<"\n";
    cout<<"the number of operation using dp is:\n"<<result2;
    return 0;
}