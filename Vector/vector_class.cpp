#include<iostream>
using namespace std;

class Vector{
    //data member
    int *arr;
    int cs;
    int ms;
public:
    Vector(int max_size=1){
        cs=0;
        ms=max_size;
        arr = new int[ms];
    }
    void push_back(const int d){
        if(cs==ms){
            //double the capacity
            int *oldArr = arr;
            ms = 2*ms;
            arr = new int[ms];
            //copy element to new array
            for(int i=0;i<cs;i++){
                arr[i]=oldArr[i];
            }
            //delete oldarr
            delete []oldArr;
        }
        arr[cs]=d;
        cs++;
    }
    void pop_back(){
        if(cs>=0){
            cs--;
        }
    }
    bool isEmpty() const{
        return cs==0;
    }
    int front() const{
        return arr[0];
    }
    int back() const{
        return arr[cs-1];
    }
    int at(int i) const{
        return arr[i];
    }
    int size() const{
        return cs;
    }
    int capacity(){
        return ms;
    }
    int operator[](const int i){
        return arr[i];
    }
};

int main(){
    Vector v(5);
    v.push_back(1);
    v.push_back(1);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

    return 0;
}