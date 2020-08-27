class ParenthesesString {
public:
    string str;
    int openCount = 0;   // open parentheses count
    int closeCount = 0;  // close parentheses count

    ParenthesesString(const string &s, int openCount, int closeCount) {
        this->str = s;
        this->openCount = openCount;
        this->closeCount = closeCount;
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        queue<ParenthesesString> combinations;
        combinations.push({"", 0, 0});

        while (!combinations.empty()) {
            ParenthesesString oldCombination = combinations.front();
            combinations.pop();

            if (oldCombination.openCount == n && oldCombination.closeCount == n) {
                results.push_back(oldCombination.str);
            } else {
                if (oldCombination.openCount > oldCombination.closeCount) {
                    string newClose = oldCombination.str + ")";
                    combinations.push({newClose, oldCombination.openCount, oldCombination.closeCount + 1});
                }
                if (oldCombination.openCount < n) {
                    string newOpen = oldCombination.str + "(";
                    combinations.push({newOpen, oldCombination.openCount + 1, oldCombination.closeCount});
                }
            }
        }
        return results;
    }
};
