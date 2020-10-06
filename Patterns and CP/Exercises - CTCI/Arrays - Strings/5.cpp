#include <iostream>
#include <string>
using namespace std;

bool oneAway (string s1, string s2){
    if(abs(s1.length()-s2.length()>1)) return false;
    
    string menor = (s1.length < s2.length ? s1: s2);
    string mayor = (s1.length > s2.length ? s2: s1);

    int index1 = 0;
    int index2 = 0;

    bool flag = false;
    for(int i=index2 ;i<mayor.length(); i++){
        if(s1[i]!=s2[i]){
            if(flag) return false;
            flag = true;
            if(s1.length()== s2.length()) index1++; //replace
        }else{
            index1++;
        }
        index2++;
    }
    return true;
}

}