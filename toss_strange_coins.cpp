#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

double tosscoin2d(double prob[], int N, int target){
    double dp[N+1][target+1];
    for(int k=0; k<=N; k++){
        for(int f=0; f<target+1; f++){
            dp[k][f]=0;
        }
    }
    dp[0][0]=1;
    for(int i=1; i<=N; i++){
        for(int j=0; j<=target; j++){
            if(j==0){
                dp[i][j]=dp[i-1][0]*(1-prob[i-1]);
            }
            else{
                dp[i][j]=dp[i-1][j]*(1-prob[i-1])+dp[i-1][j-1]*prob[i-1];
            }
        }
    }
    return dp[N][target];
}

double tosscoin1d(double prob[], int N, int target){
    vector<double> dp;
    vector<double> prev;
    prev[0]=1;
    // prob of gettinf head from 0 point is 1
    for(int i=1; i<N; i++){
        prev[i]=prev[i-1]*(1-prev[i-1]);
    }
    for(int j=0; j<N; j++){
        for(int k=j; k<N; k++){
            dp[j]=prev[k-1]*prob[k]+prev[k]*(1-prob[k]);
        }
        for(int k=j; k<N; k++){
            prev[k]=dp[k];
        }
    }
    return dp[N-1];
}

// double tosscoin(double prob[], int N, int target){
//     double temp[N+1];
//     double temp1[N+1];
//     temp[0]=1;
//     for(int i=0; i<N; i++){
//         temp1[i]=temp[i];
//         for(int j=target; j>0; j--){
//             temp1[j]=(temp[j-1]*prob[i-1])+(temp[j]*(1-prob[i-1]));
//         }
//         temp[i]=temp1[i];
//         temp[0]=temp[0]*(1-prob[i-1]);
//     }
//     return prob[target];
// }

int main(){
    cout<<"pls enter the number of coins:\n";
    int N=0;
    scanf("%d", &N);
    double prob[N];
    cout<<"pls enter the probability for tossing every coin:\n";
    for(int i=0; i<N; i++){
        scanf("%lf", &prob[i]);
    }
    cout<<"pls enter the target you are aiming for:\n";
    int target=0;
    scanf("%d", &target);
    double result=0;
    result=tosscoin2d(prob, N, target);
    cout<<"the result is:"<<result;
    return 0;
}