class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> frequency;
        int maxLength = 0;
        int start = 0;
        
        for (int end = 0; end < s.length(); end++) {
            frequency[s[end]]++;
            
            while (frequency[s[end]] > 1) {
                frequency[s[start]]--;
                if (frequency[s[start]] == 0) {
                    frequency.erase(s[start]);
                }
                start++;
            }
            
            maxLength = max(maxLength, end - start + 1);
        }
        
        return maxLength;
    }
};