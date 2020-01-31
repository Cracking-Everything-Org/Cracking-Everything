class Solution {
public:
    void combineHT(unordered_map<char, int>& htFinal,unordered_map<char, int>& htTurn) {
        if(htFinal.size()==0) {
            htFinal = htTurn;
            return ;
        }
        vector<char> toErase;
        for(auto& it: htFinal){
            if(htTurn.find(it.first) != htTurn.end()){
                htFinal[it.first] = min(it.second, htTurn[it.first]);
            } else {
                toErase.push_back(it.first);
            }
        }
        for(auto ch: toErase) htFinal.erase(ch);
    }

    vector<string> commonChars(vector<string>& A) {
        unordered_map<char,int> htFinal;
        vector<string> result;
        for(auto str : A){
            unordered_map<char,int> htTurn;
            for(int i = 0; i< str.length(); i++){
                if(htTurn.find(str[i]) != htTurn.end()){
                    htTurn[str[i]]++;
                } else {
                    htTurn[str[i]] = 1;
                }
            }
            combineHT(htFinal, htTurn);
        }
        for(auto& it: htFinal){
            while(it.second > 0) {
                char num = it.first;
                result.push_back(to_string(num));
                htFinal[it.first]--;
            }
        }
        return result;
    }
};
