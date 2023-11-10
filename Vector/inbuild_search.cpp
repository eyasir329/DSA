#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool mypredicate(int i,int j){
    return i==j;
}

int main(){
    vector<int> arr;
    for(int i=1;i<10;i++){
        arr.push_back(i*10);
    }
    int subArr[] = {40,50,60,70};
    for(int a:arr){
        cout<<a<<" ";
    }
    cout<<endl;
    for(int a:subArr){
        cout<<a<<" ";
    }
    cout<<endl;
    //using default comparison
    vector<int>::iterator it;
    it=search(arr.begin(),arr.end(),subArr,subArr+4);
    if(it!=arr.end()){
        cout<<"SubArray found at position :"<<it-arr.begin()<<endl;
    }else{
        cout<<"SubArray not found"<<endl;
    }

    //using predicate comparison
    int subArr2[] = {20,30,40};
    for(int a:subArr2){
        cout<<a<<" ";
    }
    cout<<endl;
    it = search(arr.begin(),arr.end(),subArr2,subArr2+3,mypredicate);
    if(it!=arr.end()){
        cout<<"SubArray2 found at position :"<<it-arr.begin()<<endl;
    }else{
        cout<<"SubArray2 not found"<<endl;
    }
    return 0;
}