using namespace std;
#include <vector>
#include <string>

vector<string> getPerms (string str){
    if(str == NULL) return NULL;
    
    vector<string> permutations;
    if(str.length()==0){
        permutations.push_back("");
        return permutations;
    }
    
    char first = str[0];
    string remainder = str.substr(1, str.length()-1);
    vector<string> words = getPerms(remainder);
    for(string word : words){
        for(int j=0; j<word.length; j++){
            string s = insertCharAt(word, first, j);
            permutations.push_back(s);
        }
    }
    return permutations;
}

string insertCharAt(string word, char c, int pos){
    string ret = word.substr(0,pos-1);
    ret+=c;
    ret+= word.substr(pos+1, word.length()-1);
    return ret;
}

