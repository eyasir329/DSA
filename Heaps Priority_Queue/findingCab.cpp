/*
given n cartesian points in 2d plane each represents the location of the cab. you are standing at origin, you want to know the names of the nearest k cars.

INPUT:
N=5,K=3
5 3
C1 1 1
C2 2 1
C3 3 2
C4 0 1
C5 2 3
Output:
C4
C1
C2
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Car{
    public:
        string id;
        int x,y;
        Car(string id,int x,int y){
            this->id = id;
            this->x = x;
            this->y = y;
        }
        int dist() const{
            return x*x+y+y;
        }
};

class CarCompare{
    public:
    bool operator()(const Car A,const Car B){
        return A.dist()<B.dist();
    }
};

void printNearestCars(vector<Car>cars,int k){
    // create a max heap of size k
    priority_queue<Car,vector<Car>,CarCompare>max_heap(cars.begin(),cars.begin()+k);
    // remaining cars
    for(int i=k;i<cars.size();i++){
        auto car = cars[i];
        if(car.dist()<max_heap.top().dist()){
            max_heap.pop();//remove the root node largest
            max_heap.push(car);
        }
    }
    // print all the cars inside the heap they will be smallest
    vector<Car>output;
    while (!max_heap.empty())
    {
        output.push_back(max_heap.top());
        max_heap.pop();
    }

    reverse(output.begin(),output.end());
    
    for(auto car:output){
       cout<<car.id<<endl; 
    }
    
}

int main(){
    int N,K;
    cin>>N>>K;
    string id;
    int x,y;
    vector<Car>cars;
    for(int i=0;i<N;i++){
        cin>>id>>x>>y;
        Car car(id,x,y);
        cars.push_back(car);
    }
    printNearestCars(cars,K);
    return 0;
}