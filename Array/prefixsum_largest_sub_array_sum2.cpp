#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void printSubarraySum(int arr[],int n){
    int prefix[n];
    prefix[0]=arr[0];
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1]+arr[i];
    }
    int largest_sum=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int subarraySum = i>0? prefix[j]-prefix[i-1]:prefix[j];
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