#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

int count(string s){
    int n = s.size();
        if(n <= 0){
            return 0;
        }
        vector<int> dp(n+1);
        dp[n] = 1; // ..... 1
        for(int i=n-1; i>=0 ; i--){
            if(s[i] == '0'){ // invalid case
                dp[i] = 0;
                continue;
            }  
            dp[i] = dp[i+1];
            
            int num=0;
            for(int j=i; j<; j++){
                if(s[j] < '0' || s[j] > '9'){

                }
                num=num*10+
            }
            
            if( 10 <= num && num <= 26 ){
                dp[i] = dp[i+1] + dp[i+2];
            }
        }

       
        return dp[0];
}

int main(){
    string s;
    cout<<"pls enter a string containging only digits\n";
    cin>>s;

}