#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void printSubarray(int arr[],int n){
    vector<int> tSum;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int t{0};
            for(int k=i;k<=j;k++){
                cout<<arr[k]<<",";
                t+=arr[k];
            }
            tSum.push_back(t);
            cout<<" Sum:"<<t<<endl;
        }
    }

    for(int x:tSum){
        cout<<x<<" ";
    }

    cout<<"\nMax Sum :"<<*max_element(tSum.begin(),tSum.end())<<endl;
}

int main(){
    int arr[] = {10,20,30,40,50,60};
    int n = sizeof(arr)/sizeof(arr[0]);
    printSubarray(arr,n);

    return 0;
}