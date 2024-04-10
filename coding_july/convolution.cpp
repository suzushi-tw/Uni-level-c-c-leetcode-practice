#include<stdio.h>
#include<iostream>
using namespace std;

void convolution(int a[], int b[], int c[], int a_num, int b_num){
    for(int i=0; i<a_num+b_num-1; i++){
        c[i]=0;
        for(int j=0; j<3; j++){
            if(i-j >=0 && i-j<5){
                cout<<"loop "<<j<<" ";
                cout<<"this is a "<<a[i-j]<<" ";
                cout<<"this is b "<<b[j]<<" ";
                c[i]+=a[i-j]*b[j];
                cout<<"\n";
            }
        }
    }
}

int main(){
    int a_num=0;
    cout<<"pls enter the size for array a:\n";
    scanf("%d", &a_num);
    int a[a_num];
    int b_num=0;
    cout<<"pls enter the size for array b:\n";
    scanf("%d", &b_num);
    int b[b_num];
    cout<<"pls enter the integer for array a:\n";
    for(int i=0 ;i<a_num; i++){
        scanf("%d", &a[i]);
    } 
    cout<<"pls enter the integer for array b:\n";
    for(int k=0; k<b_num; k++){
        scanf("%d", &b[k]);
    }
    int c[a_num+b_num-1];

    convolution(a, b, c, a_num, b_num);
    for(int d=0; d<a_num+b_num-1; d++){
        cout<<c[d]<<" ";
    }
    return 0;
}