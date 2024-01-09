#include<vector>

using namespace std;

class Heap{
    vector<int>v;

    public:
        Heap(int default_size = 10){
            v.reserve(default_size+1);
            v.push_back(-1);
        }

        // insertion/push
        void push(int data){
            // add data at the end of the loop
            v.push_back(data);
            int idx = v.size()-1;
            int parent = idx/2;
            while(idx>1 and v[idx]<v[parent]){
                swap(v[idx],v[parent]);
                idx = parent;
                parent = parent/2;
            }
        }

        // heapify
        void heapify(int i){
            int left = 2*i;
            int right = 2*i+1;
            int minIdx = i;
            if(left<v.size() and v[left]<v[i]){
                minIdx = left;
            }
            if(right<v.size() and v[right]<v[minIdx]){
                minIdx = right;
            }
            if(minIdx!=i){
                swap(v[i],v[minIdx]);
                heapify(minIdx);
            }
        }

        // return first==big elememt in minheap
        int top(){
            return v[1];
        }

        bool empty(){
            return v.size()==1;
        }

        // remove min element
        void pop(){
            // swap fast and last element
            int idx = v.size()-1;
            swap(v[1],v[idx]);
            v.pop_back();
            heapify(1);
        }

};