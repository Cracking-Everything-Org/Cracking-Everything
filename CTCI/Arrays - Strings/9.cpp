#include <string>
using namespace std; 

bool stringRotation(string &s1, string s2){
    if(s1.length()!=s2.length()) return false;
    int chances = s1.length();
    while(chances>0){
        if(s1.isSubstring(s2)) return true;
        else{
            string cup = s1.substr(s1.length()-chances+1, s1.length());
            cup+= s1.substr(0,s1.length()-chances+1);
            s1=cup;
        }
        chances--;
    }
    return false;
}