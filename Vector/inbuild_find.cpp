#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    //process-1
    //using std::find with array and pointer
    int arr[] = {10,20,30,40};
    int * p;
    int key = 20;
    p=find(arr,arr+4,key);
    //p=find(arr.begin(),arr.end(),key)
    if(p!=arr+4){
        cout<<"key is found :"<<*p<<" \n";
    }else{
        cout<<"key is not found in our array"<<endl; 
    }

    //find location
    //process-2 using iterator
    //array to vector copy

    vector<int> vi(arr,arr+4);
    for(int i=0;i<vi.size();i++){
        cout<<vi[i]<<" ";
    }
    cout<<endl;
    vector<int>::iterator it;
    it = find(vi.begin(),vi.end(),key);
    if(it!=vi.end()){
        cout<<key<<" key found in vi at :"<<it-vi.begin()<<endl;
    }else{
        cout<<"key is not found"<<endl;
    }
    
    return 0;
}