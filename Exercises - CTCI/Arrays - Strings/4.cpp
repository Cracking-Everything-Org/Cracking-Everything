#include <iostream>
#include <string>
using namespace std;

bool palPerm (string str) {
    if(str == "") return true; // ASCII
    char list[128] = {NULL};
    for(int i = 0; i<str.length;i++){
        if(list[str[i]]==1){
            list[str[i]]--;
        }
        else{
            if(str[i] != ' '){
                list[str[i]]++;
            }
        }
    }
    bool flag = false;
    for(int i=0; i<sizeof(list);i++){
        if(list[i] == 1 && flag){
            return false;
        }
        flag = true;
    }
    return true;
}
