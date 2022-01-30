class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int currLength = 0;
        int windowStart = 0;
        int windowEnd;
        unordered_map<char,int> ht;
        for (windowEnd = 0; windowEnd < s.length(); windowEnd++) {
            ht[s[windowEnd]] ++;
            currLength ++;
            while (ht[s[windowEnd]]>1) {
                ht[s[windowStart]]--;
                windowStart++;
                currLength--;
            }
            maxLength = max(maxLength, currLength);
        }
        return maxLength;
    }
};
