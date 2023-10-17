#include<iostream>

using namespace std;

void bubble_sort(int arr[],int n){
    for(int times=1;times<=n-1;times++){
        for(int j=0;j<=n-times-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    int arr[]={-1,-3,-12,0,7,-10,9,15};
    int n= sizeof(arr)/sizeof(int);

    cout<<"Primary Array:";
    for(int c:arr){
        cout<<c<<" ";
    }

    bubble_sort(arr,n);

    cout<<"\n"<<"After Sorting Array:";
    for(int c:arr){
        cout<<c<<" ";
    }
    return 0;
}