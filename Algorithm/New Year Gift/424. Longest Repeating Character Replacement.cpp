class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> frequency;
        int size = s.length();
        int maxLength = 0; 
        int maxRepeatLetterCount = 0;
        
        int start = 0;
        for (int end = 0; end < size; end++) {
          frequency[s[end]]++;
          maxRepeatLetterCount = max(maxRepeatLetterCount, frequency[s[end]]);
            
          if (end - start + 1 - maxRepeatLetterCount > k) {
            frequency[s[start]]--;
            start++;
          }

          maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
      }
};