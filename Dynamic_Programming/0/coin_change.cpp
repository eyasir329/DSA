#include <bits/stdc++.h>
using namespace std;

const int INF = 100000;

int coin_change(int d[],int n,int k){
    int m[n+1];
    m[0]=0;
    int i,j;
    for(int j=1;j<=n;j++){
        int minimum = INF;
        for(i=1;i<=k;i++){
            if(j>=d[i]){
                minimum = min(minimum,1+m[j-d[i]]);
            }
        }
        m[j]=minimum;
    }
    return m[n];
}

int main(){
    int d[] = {0,1,2,5};
    cout<<"Minimum Number of Coin : "<<coin_change(d,5,3)<<endl;

    return 0;
}