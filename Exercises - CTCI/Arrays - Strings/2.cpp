#include <iostream>
#include <string>
using namespace std;

bool permutation(string str1, string str2){
    if(str1.length() != str2.length()) return false;
    int counter[128] = {0}; // ASCII
    for(unsigned int i=0; i<str1.length();i++){
        counter[str1[i]]++;
    }
    for(unsigned int j=0; j<str2.length();j++){
        counter[str2[j]]--;
        if(counter[str2[j]]<0) return false;
    }
    return true;
}

int main(){
  cout << permutation("","");
  cout << permutation("ab","ac");
  cout << permutation("acb","cba");
}