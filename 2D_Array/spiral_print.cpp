/*
input:  1  2  3  4
        12 13 14 5
        11 16 15 6
        10 9  8  7
output: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
*/

#include<iostream>

using namespace std;

void spiralPrint(int arr[][4],int n,int m){
    //4 variable
    int startRow = 0;
    int endRow = n-1;
    int startCol = 0;
    int endCol = m-1;
    //outer loop - traverse array boundary
    while(startCol<=endCol and startRow<=endRow){
        //start row
        for(int col=startRow;col<=endCol;col++){
            cout<<arr[startRow][col]<<" ";
        }
        //end col
        for(int row = startRow+1;row<=endRow;row++){
            cout<<arr[row][endCol]<<" ";
        }
        //end row
        for(int col=endCol-1;col>=startCol;col--){
            cout<<arr[endRow][col]<<" ";
            if(startRow==endRow) break;
        }
        //start col
        for(int row=endRow-1;row>=startRow+1;row--){
            cout<<arr[row][startCol]<<" ";
            if(startCol==endCol) break;
        }
        startRow++;
        endRow--;
        startCol++;
        endCol--;
    } 
}

int main(){
    int n=4,m=4;
    int arr[4][4]={{1,2,3,4},{12,13,14,5},{11,16,15,6},{10,9,8,7}};
    cout<<"Initial Array :"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Spiral Array :"<<endl;
    spiralPrint(arr,n,m);
    return 0;
}