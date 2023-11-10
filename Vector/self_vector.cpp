#include<iostream>
#include "Vector.h"

using namespace std;
int main(){
    Vector<int> arr;
    for(int i=0;i<10;i++){
        arr.push_back(i+1);
    }
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}