class Solution {
public:
    string getHint(string secret, string guess) {
        string ans = "";
        int bulls = 0;
        int cows = 0;
        unordered_map<char,int> ht;

        for (int i = 0; i < secret.length(); i++) {
            if (ht.find(secret[i]) != ht.end()) {
                ht[secret[i]]++;
            } else ht[secret[i]] = 1;
        }

        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
                ht[secret[i]]--;
                if (ht[secret[i]] == 0) ht.erase(secret[i]);
            }
        }
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] != guess[i] && ht.find(guess[i]) != ht.end()) {
                cows++;
                ht[guess[i]]--;
                if (ht[guess[i]] == 0) ht.erase(guess[i]);
            }
        }
        if (bulls > 0) {
            ans += to_string(bulls) + "A";
        } else ans = "0A";

        if (cows > 0) {
            ans += to_string(cows) + "B";
        } else ans += "0B";
        return ans;
    }
};
