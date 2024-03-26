#include <iostream>
using namespace std;

int binary_search(int arr[],int n,int key){
    int s = 0;
    int e = n - 1;
    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid]==key){
            return mid;
        }else if(arr[mid]>key){
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }
    return -1;
}

int main() {
    cout << "Binary Search Algorithms\n";
    int arr[] = {3,4,5,8,10,13,21,28,32};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 32;
    int k = binary_search(arr,n,key);
    if(k!=-1){
        cout<<key<<" found at index : "<<k<<endl;
    }else{
        cout<<"Key not found"<<endl;
    }
    return 0;
}