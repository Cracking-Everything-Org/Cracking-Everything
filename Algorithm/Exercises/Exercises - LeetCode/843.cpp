class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int guesses = 0;
        while (guesses < 10) {
            string guessWord = wordlist[rand() % wordlist.size()];
            int matches = master.guess(guessWord);
            vector<string> candidates;
            for (string word : wordlist) {
                if (getMatches(guessWord, word) == matches) {
                    candidates.push_back(word);
                }
            }
            wordlist.swap(candidates); // los saco de la lista
            guesses++;
        }
    }
    
private:
    int getMatches(string word1, string word2) {
        int match = 0;
        for (int i = 0; i < word1.size(); ++i) {
            if (word1[i] == word2[i]) {
                match++;
            }
        }
        return match;
    }
};