class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> letterFrequencyMap;
        int size = s.length();
        int maxLength = 0;
        int maxRepeatLetterCount = 0;

        int windowStart = 0;
        for (int windowEnd = 0; windowEnd < size; windowEnd++) {
          letterFrequencyMap[s[windowEnd]]++;
          maxRepeatLetterCount = max(maxRepeatLetterCount, letterFrequencyMap[s[windowEnd]]);

          if (windowEnd - windowStart + 1 - maxRepeatLetterCount > k) {
            letterFrequencyMap[s[windowStart]]--;
            windowStart++;
          }

          maxLength = max(maxLength, windowEnd - windowStart + 1);
        }

        return maxLength;
      }
};
