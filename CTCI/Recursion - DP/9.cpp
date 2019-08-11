using namespace std;
#include <string>
#include <unordered_set>

unordered_set<string> generateParens(int remaining){
    unordered_set<string> set;
    if(remaining == 0){
        set.insert("");
    }else{
        unordered_set prev = generateParens(remaining-1);
        for(string str : prev){
            for(int i=0; i< str.length(); i++){
                if(str[i] == '('){
                    string s = insertInside(str, i);
                    set.insert(s);
                }
            }
            set.insert("()"+str);
        }
    }
    return set;
}