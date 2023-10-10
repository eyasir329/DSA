#include <iostream>
using namespace std;

void reverseArray(int arr[],int n){
    int s = 0;
    int e = n - 1;
    while(s<=e){
        swap(arr[s],arr[e]);
        s+=1;
        e-=1;
    }
}

int main() {
    cout << "Binary Search Algorithms\n";
    int arr[] = {3,4,5,8,10,13,21,28,32};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    reverseArray(arr,n);
    //in cpp classical array is like pass by references

    for(int j=0;j<n;j++){
        cout<<arr[j]<<" ";
    }
    cout<<endl;
    
    return 0;
}