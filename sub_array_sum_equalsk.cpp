#include<stdio.h>
#include<iostream>
using namespace std;

int sumusing_slidingwindow(int a[], int sum, int N){
    int current=0;
    int start=0;
    int end=0;
    int count=0;
    for(int i=0; i<=N; i++){
        while(current>sum && start<i-1){
            current=current-a[start];
            start++;
        }
        if(current==sum){
            count++;
        }
        if(i<N){
            current=current+a[i];
        }
    }
    return count;
}

int subarraysum(int a[], int sum, int N){
    int answer=0;
    for(int k=0; k<N; k++){
        int temp=0;
        for(int j=k; j<N; j++){
            temp+=a[j];
            if(temp==sum){
                answer++;
            }
        }
    }
    return answer;
}

int main(){
    cout<<"pls enter the size of the array:\n";
    int N=0;
    scanf("%d", &N);
    int a[N];
    cout<<"pls enter the numbers of the array:\n";
    for(int i=0; i<N; i++){
        scanf("%d", &a[i]);
    }
    cout<<"pls enter the sum:\n";
    int sum=0;
    scanf("%d", &sum);
    int result=0;
    result=subarraysum(a, sum, N);
    int result2=0;
    result2=sumusing_slidingwindow(a, sum, N);
    cout<<"the number of possible sums are:"<<result;
    cout<<"the result using sliding window is:"<<result2;
    return 0;
}