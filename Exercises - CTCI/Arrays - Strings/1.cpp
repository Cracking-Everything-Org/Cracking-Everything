#include <iostream>
#include <string>
using namespace std; 

bool allUnique(string str){
    
    if(str.length()==0) return true;
    bool charsSeen[str.length()] = {false};
    for(unsigned int i=0; i<str.length(); i++){
        int charToIndex = str[i] - 'a';
        if(charsSeen[charToIndex]) return false;
        else charsSeen[charToIndex] = true;
    }
    return true;
}
    
int main() {
    cout<< allUnique("");
    cout<< allUnique("abc");
    cout<< allUnique("aaa");
    return 0;
}