class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> ht;
        unordered_map<string, int> bannedWords;
        for (auto bannedWord : banned) {
            if (bannedWords.find(bannedWord) != bannedWords.end()) {
                bannedWords[bannedWord] = 1;
            }
        }
        vector<string> paragraphWords = findWords(paragraph);
        for (auto pWord : paragraphWords) {
            string pWordLower = tolower(pWord);
            if (ht.find(pWordLower) != ht.end()) {
                ht[pWordLower]++;
            } else {
                ht[pWordLower] = 1;
            }
        }
        string mostCommon = "";
        for (auto entry : ht) {
            string entryLower = tolower(entry.first);
            mostCommon = ht[entryLower] > ht[mostCommon] ? entryLower : mostCommon;
        }
        return mostCommon;
    }

    vector<string> findWords(string paragraph) {
        vector<string> ans;
        int end = 0;
        string toAdd = "";
        for (int end = 0; end < paragraph.length(); end++) {
            if (paragraph[end] != ' ' && paragraph[end] != ',' && paragraph[end] != '.') {
                toAdd += paragraph[end];
                if (end == paragraph.length() - 1) {
                ans.push_back(toAdd);
                }
            } else {
                ans.push_back(toAdd);
                toAdd = "";
            }
        }
        return ans;
    }
};
