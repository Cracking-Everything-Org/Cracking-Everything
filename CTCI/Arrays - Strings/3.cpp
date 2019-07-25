#include <iostream>
#include <string>
using namespace std;

string URLify(string str1, int realSize){
    if(realSize==0) return str1;
    string result ="";
    for(unsigned int i = 0; i<realSize; i++){
        if(str1[i] != ' ') result += str1[i];
        else result += "%20";
    }
    return result;
}

int main(){
  cout << URLify("a b",3);
  cout << " ";
  cout << URLify("",0);
  cout << " ";
  cout << URLify(" a  ",2);
}
