#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void printSubarraySum(int arr[],int n){
    int largest_sum=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int subarraySum=0;
            for(int k=i;k<=j;k++){
                subarraySum+=arr[k];
            }
            largest_sum = max(largest_sum,subarraySum);
        }
    }
    cout<<"Largest Sub Array Sum :"<<largest_sum<<endl; 
}

int main(){
    int arr[] = {10,20,30,40,50,60};
    int n = sizeof(arr)/sizeof(arr[0]);
    printSubarraySum(arr,n);

    return 0;
}