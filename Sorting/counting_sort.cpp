#include<iostream>
#include<vector>

using namespace std;

void counting_sort(int arr[],int n){ 
    //consider we only have positive number
    int largest = -1;
    for(int i=0;i<n;i++){
        largest = max(largest,arr[i]);
    }

    //count vector
    vector<int> freq(largest+1,0);
    //update the frequency vector
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }

    int j=0;
    for(int i=0;i<=largest;i++){
        while (freq[i]>0)
        {
            arr[j] = i;
            freq[i]--;
            j++;
        }
    }
    return;
}

int main(){
    int arr[]={12,39,14,0,7,10,9,15};
    int n = sizeof(arr)/sizeof(int);

    cout<<"Primary Array:";
    for(int c:arr){
        cout<<c<<" ";
    }

    counting_sort(arr,n);

    cout<<"\n"<<"After Sorting Array:";
    for(int c:arr){
        cout<<c<<" ";
    }
    return 0;
}