using namespace std;
#include <vector>
#include <string>
#include <unordered_map>

vector<string> printPerms(string s){
    vector<string> result;
    unordered_map<char, int> map = buildFreq(s);
    printPerms(map, "", s.length(), result);
    return result;
}

unordered_map<char, int> buildFreq(string s){
    unordered_map<char, int> map;
    for(char c: s){
        if(!map[c]){
            map[c]=1;
        } else map[c]++;
    }
    return map;
}

void printPerms(unordered_map<char, int> map, string prefix, int remaining, vector<string> result){
    if(remaining = 0){
        result.push_back(prefix);
        return;
    }
    for(auto c : map){
        int count = c.second;
        if(count>0){
            map.insert[c, count-1];
            printPerms(map, prefix + c.first, remaining-1, result);
            map.insert[c, count];
        }
    }
}