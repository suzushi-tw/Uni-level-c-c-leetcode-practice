#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<pair<int,int>> findpairs(int nums1[], int n1, int nums2[], int n2, int k){
    vector<pair<int,int>> answer;
    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            int sum=nums1[i]+nums2[j];
            if(answer.size()<k){
                answer.push_back({nums1[i], nums2[j]});
            }
            else if(sum<answer.back().first+answer.back().second){
                answer.pop_back();
                answer.push_back({nums1[i], nums2[j]});
            }
            int n=answer.size();                    
            bool swap=true;
            for(int f=0; f<n && swap ; f++){
                swap=false;
                for(int k=0; k<n-1-j; k++){
                    if(answer[k].first+answer[k].second>answer[k+1].first+answer[k+1].second){
                        pair<int,int>temp;
                        temp=answer[k];
                        answer[k]=answer[k+1];
                        answer[k+1]=temp;
                        swap=true;
                    }
                }
            }
        }
    }
    return answer;
}

int main(){
    int n1=0;
    cout<<"pls enter amount of numbers for first array:\n";
    scanf("%d", &n1);
    int nums1[n1];
    for(int i=0; i<n1; i++){
        scanf("%d", &nums1[i]);
    }
    int n2=0;
    cout<<"pls enter amount of numbers for the second array:\n";
    scanf("%d", &n2);
    int nums2[n2];
    for(int k=0; k<n2; k++){
        scanf("%d", &nums2[k]);
    }
    int k=0;
    cout<<"enter the amount of pairs of smallest number you wish to find\n";
    scanf("%d", &k);
    vector<pair<int,int>> result;
    result=findpairs(nums1, n1, nums2, n2, k);
    cout<<"the k pair with smallest sum is:\n";
    for(int i=0; i<k; i++){
        cout<<result[i].first<<" "<<result[i].second<<" ";
    }
    return 0;
}