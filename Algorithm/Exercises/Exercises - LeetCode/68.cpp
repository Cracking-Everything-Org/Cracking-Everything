class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        
        int i = 0;
        int n = words.size();
        while (i < n) {
            int j = i + 1;
            int lineLength = words[i].length();
            while (j < n && (lineLength + words[j].length() + (j - i - 1)) < maxWidth) {
                lineLength += words[j].length();
                j++;
            }
            
            int diff = maxWidth - lineLength;
            int numberOfWords = j - i;
            if (numberOfWords == 1 || j >= n) {
                result.push_back(leftJustify(words, diff, i, j));
            } else {
                result.push_back(middleJustify(words, diff, i, j));
            }
            
            i = j;
        }
        
        return result;
    }
    
    string leftJustify(vector<string> words, int diff, int i, int j) {
        int spacesOnRight = diff - (j - i - 1);
        
        string result = words[i];
        for (int k = i + 1; k < j; ++k) {
            result += " " + words[k];
        }
        
        for (int space = 0; space < spacesOnRight; space++) {
            result += " ";
        } 
        
        return result;
    }
    
    string middleJustify(vector<string> words, int diff, int i, int j) {
        int spacesNeeded = j - i - 1;
        int spaces = diff / spacesNeeded;
        int extraSpaces = diff % spacesNeeded;
        
        string result = words[i];
        for (int k = i + 1; k < j; ++k) {
            int spacesToApply = spaces + (extraSpaces-- > 0 ? 1 : 0);
            for (int space = 0; space < spacesToApply; space++) {
                result += " ";  
            }
            result += words[k];
        }
        
        return result;
    }
};