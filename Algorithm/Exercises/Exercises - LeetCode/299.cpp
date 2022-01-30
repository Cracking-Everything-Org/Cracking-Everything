class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        
        unordered_map<char, int> candidateCows;
        
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                candidateCows[secret[i]]++;
            }
        }
        
        for (int i = 0; i < guess.length(); i++) {
            if (secret[i] != guess[i]) {
                if (candidateCows.find(guess[i]) != candidateCows.end()) {
                    cows++;
                    candidateCows[guess[i]]--;
                    if (candidateCows[guess[i]] == 0) {
                        candidateCows.erase(guess[i]);
                    }
                }
            }
        }
        
        string result = to_string(bulls) + "A" + to_string(cows) + "B";
        return result;
    }
};