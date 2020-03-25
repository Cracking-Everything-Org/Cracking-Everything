class Solution {
public:
    vector<string> letterCombinations(string digits) {
        const vector<string> mapping = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> output;
        if(digits.size() == 0) return output;
        dfs(digits, "", 0, mapping, output);
        return output;
    }

    void dfs(string digits, string current, int index, const vector<string>& mapping, vector<string>& output){
        if(index == digits.length()){
            output.push_back(current);
            return;
        }
        string letters = mapping[digits[index] - '0'];
        for(int i=0; i<letters.length(); i++)
            dfs(digits, current+letters[i], index+1, mapping, output);
    }
};
