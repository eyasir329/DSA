#include<iostream>
#include "stackLL.h"

using namespace std;

int main(){
    stack<char>s;
    s.push('h');
    s.push('e');
    s.push('l');
    s.push('l');
    s.push('0');

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}