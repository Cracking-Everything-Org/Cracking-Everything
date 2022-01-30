class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> hs;
        bool prefix;
        bool plus;
        string current;
        for (string email : emails) {
            current = "";
            prefix = true;
            plus = false;
            for (int i = 0; i < email.length(); i++) {
                if (email[i] == '@') {
                    prefix = false;
                }
                if (email[i] == '+') {
                    plus = true;
                }
                if (email[i] != '.' && email[i] != '+' && prefix && !plus) {
                    current += email[i];
                }
                if (!prefix) {
                    current += email[i];
                }
            }
            if (!hs.count(current)) {
                hs.insert(current);
            }
        }
        return hs.size();
    }
};
