#include<stdio.h>
#include<algorithm>
#include<string>
#include<iostream>
#include<string.h>
using namespace std;

// (()(()((()(0)))))

int main(){
    string str;
    cin >> str;

    int num = 0;

    for(int i=0; i<str.size(); i++)
    {
        if(str[i] == '(')
            num++;
        else if(str[i] == ')')
            num--;
        else if(str[i] == '0')
            break;
    }

    cout << num << endl;

    return 0;
}
