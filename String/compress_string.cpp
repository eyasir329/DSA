//sample input : aaabbccddee abcd
//sample output: a3b2c2d2e2  abcd
//if compressed string is bigger than original then return original string
#include<iostream>
#include<string>

using namespace std;

string compressString(string str){
    int n= str.length();
    string output;
    for(int i=0;i<n;i++){
        int count = 1;
        while(i<n-1 and str[i+1]==str[i]){
            count++;
            i++;
        }
        output+=str[i];
        output+=to_string(count);
    }
    if(output.length()>str.length()){
        return str;
    }
    return output;
}

int main(){
    string str;
    getline(cin,str);
    cout<<compressString(str)<<endl;
    return 0;
}