#include<iostream>

using namespace std;

void insertion_sort(int arr[],int n){
    for(int i=1;i<=n-1;i++){
        int current = arr[i];
        int prev = i - 1;
        while(prev>=0 and arr[prev]>current){
            arr[prev+1]=arr[prev];
            prev = prev -1;
        }
        arr[prev+1] = current;
    }
}

int main(){
    int arr[]={-1,-3,-12,0,7,-10,9,15};
    int n= sizeof(arr)/sizeof(int);

    cout<<"Primary Array:";
    for(int c:arr){
        cout<<c<<" ";
    }

    insertion_sort(arr,n);

    cout<<"\n"<<"After Sorting Array:";
    for(int c:arr){
        cout<<c<<" ";
    }
    return 0;
}