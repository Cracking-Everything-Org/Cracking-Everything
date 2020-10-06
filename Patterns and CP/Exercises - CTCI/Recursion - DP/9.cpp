using namespace std;
#include <string>
#include <vector>
#include <unordered_set>

void addParen(vector<string> list, int leftRem, int rightRem, string str, int index){
    if(leftRem < 0 || rightRem < leftRem) return;

    if(leftRem == 0 && rightRem ==0){
        list.push_back(str);
    } else{
        str[index] = '(';
        addParen(list, leftRem-1 , rightRem, str, index+1);
        
        str[index] = ')';
        addParen(list, leftRem , rightRem-1, str, index+1);
    }
}

vector<string> generateParens(int remaining){
    vector<string> result;
    addParen(result, remaining, remaining, "", 0);
    return result;
}

unordered_set<string> generateParens2(int remaining){
    unordered_set<string> set;
    if(remaining == 0){
        set.insert("");
    }else{
        unordered_set prev = generateParens2(remaining-1);
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

string insertInside(string str, int i){
    string result = str.substr(0, i+1);
    result += "()";
    result += str.substr(i+1, str.length()-1);
    return result;
}