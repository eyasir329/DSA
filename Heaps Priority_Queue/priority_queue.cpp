#include<iostream>
#include<queue>
#include<vector>
#include "heap.h"

using namespace std;

class Compare{
    public:
        bool operator()(int a,int b){
            return a>b;
        }
};

int main(){
    int arr[] = {10,15,20,13,6,90};
    int n = sizeof(arr)/sizeof(arr[0]);

    // O(N+KlogN)<sorting-O(NlogN)
    // 90-20-15-13-10-6 parent>=child
    cout<<"MaxHeap"<<endl;
    priority_queue<int>maxHeap;
    for(auto x:arr){
        maxHeap.push(x);
    }
    while(!maxHeap.empty()){
        cout<<maxHeap.top()<<endl;
        maxHeap.pop();
    }
    // 6-10-13-15-20-90
    cout<<"MinHeap"<<endl;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    for(auto x:arr){
        minHeap.push(x);
    }
    while(!minHeap.empty()){
        cout<<minHeap.top()<<endl;
        minHeap.pop();
    }

    // 6-10-13-15-20-90
    cout<<"MinHeap Custom Compare"<<endl;
    priority_queue<int,vector<int>,Compare>minHeapCustom;
    for(auto x:arr){
        minHeapCustom.push(x);
    }
    while(!minHeapCustom.empty()){
        cout<<minHeapCustom.top()<<endl;
        minHeapCustom.pop();
    }

    // own librery
    cout<<"custom librery"<<endl;
    Heap heap(n);
    for(auto x:arr){
        heap.push(x);
    }
    while(!heap.empty()){
        cout<<heap.top()<<endl;
        heap.pop();
    }
    return 0;
}