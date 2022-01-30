class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string stringSentence = "";
        for (string word : sentence) {
            stringSentence += word + " ";
        }
        int sentenceLength = stringSentence.length();
        
        int cursor = 0;
        for (int row = 0; row < rows; ++row) {
            cursor += cols;
            if (stringSentence[cursor % sentenceLength] == ' ') {
                cursor++;
            } else {
                while (cursor >= 0 && stringSentence[cursor % sentenceLength] != ' ') {
                    cursor--;
                }
                cursor++;
            }
        }
        
        return cursor / sentenceLength;
    }
};