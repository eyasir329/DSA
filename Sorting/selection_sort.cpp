#include<iostream>

using namespace std;

void selection_sort(int arr[],int n){
    for(int pos=0;pos<=n-2;pos++){
        int current = arr[pos];
        int min_position = pos;
        for(int j=pos;j<n;j++){
            if(arr[j]<arr[min_position]){
                min_position = j;
            }
        }
        swap(arr[min_position],arr[pos]);
    }
}

int main(){
    int arr[]={-1,-3,-12,0,7,-10,9,15};
    int n= sizeof(arr)/sizeof(int);

    cout<<"Primary Array:";
    for(int c:arr){
        cout<<c<<" ";
    }

    selection_sort(arr,n);

    cout<<"\n"<<"After Sorting Array:";
    for(int c:arr){
        cout<<c<<" ";
    }
    return 0;
}