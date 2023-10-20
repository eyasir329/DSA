//sample input : SNNNEWE
//sample output : NNE
#include<iostream>

using namespace std;

int main(){
    char route[1000];
    cin.getline(route,1000);
    int x = 0;
    int y = 0;
    for(int i=0;route[i]!='\0';i++){
        switch(route[i]){
            case 'N':
                    y++;
                    break;
            case 'S':
                    y--;
                    break;
            case 'E':
                    x++;
                    break;
            case 'W':
                    x--;
                    break;
        }
    }

    cout<<"Final x and y is :"<<x<<","<<y<<endl;
    //+,+ cordinates
    if(x>=0 and y>=0){
        while (y--){
            cout<<"N";
        }
        while(x--){
            cout<<"E";
        }
    }
    //+,- cordinates
    else if(x>=0 and y<0){
        while (y++){
            cout<<"S";
        }
        while(x--){
            cout<<"E";
        }
    }
    //-,- cordinates
    else if(x<0 and y<0){
        while (y++){
            cout<<"S";
        }
        while(x++){
            cout<<"W";
        }
    }
    //-,+ cordinates
    else if(x<0 and y>=0){
        while (y--){
            cout<<"N";
        }
        while(x++){
            cout<<"W";
        }
    }
    cout<<endl;
    return 0;
}