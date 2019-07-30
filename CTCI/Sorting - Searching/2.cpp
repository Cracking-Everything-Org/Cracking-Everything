using namespace std;
#include <iostream> 
#include <string>
#include <vector>
#include <unordered_map>

void groupAnagrams(vector<string> list){
    unordered_map<string, string> HT;
    for(string s: list){
        string key = sortChar(s);
        HT.insert({key,s});
    }

    int index = 0;
    vector<string> strings;
    for(auto it :HT){
        for(auto str :it.second){
            list[index]=str;
            index++;
        }
    }
}

string sortChar(string s){
    vector<char> sVector (s.begin(),s.end());
    sort(sVector.begin(), sVector.end());
    string str (sVector.begin(),sVector.end());
    return str;
}