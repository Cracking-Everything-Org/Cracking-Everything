class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // BFS
        unordered_set<string> ht(wordList.begin(), wordList.end());
        queue<string> toProcess;
        toProcess.push(beginWord);
        int distance = 1;
        while (!toProcess.empty()) {
            int n = toProcess.size();
            for (int i = 0; i < n; i++) {
                string word = toProcess.front();
                toProcess.pop();
                if (word == endWord) {
                    return distance;
                }
                ht.erase(word);
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if (ht.find(word) != ht.end()) {
                            toProcess.push(word);
                        }
                     }
                    word[j] = c;
                }
            }
            distance++;
        }
        return 0;
    }
};
