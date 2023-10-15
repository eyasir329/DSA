#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void printSubarraySum(int arr[],int n){
    int cs = 0;
    int largest = 0;

    for(int i=0;i<n;i++){
        cs = cs + arr[i];
        if(cs<0){
            cs = 0;
        }
        largest = max(largest,cs);
    }
    cout<<"Largest Sub Array Sum :"<<largest<<endl; 
}

int main(){
    int arr[] = {10,20,30,40,50,60};
    int n = sizeof(arr)/sizeof(arr[0]);
    printSubarraySum(arr,n);

    return 0;
}