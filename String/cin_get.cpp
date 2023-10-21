#include<iostream>

using namespace std;

int main(){
    char sentence[1000];
    //one character at a time but read everything including whitespace
    char temp = cin.get();
    //getline(cin,str) can input all thing
    int len = 0;
    while(temp!='\n'){
        sentence[len++] = temp;
        temp = cin.get();
    } 
    sentence[len] = '\0';
    cout<<sentence<<endl;
    return 0;
}