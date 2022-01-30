#include <iostream>
#include <string>
using namespace std;

string compression(string s1){
    if(s1.length() == 0) return s1;
    char ch = s1[0];
    int counter = 1;
    string ret="";
    for(int i=0;i<s1.length();i++){
        if(s1[i]!=ch){
            ret+=ch+counter;
            ch=s1[i];
            counter=1;
        }else{
            counter++;
        }
    }
    return ret;
}