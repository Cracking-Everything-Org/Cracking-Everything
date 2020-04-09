class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int maxLength = 0;
        int currentLength = 0;
        int startWindow = 0;

        unordered_map<char, int> ht;
        for (int endWindow = 0; endWindow < s.length(); endWindow++) {
            currentLength++;
            ht[s[endWindow]]++;

            while (ht.size() > k) {
                ht[s[startWindow]]--;
                if (ht[s[startWindow]] == 0) {
                    ht.erase(s[startWindow]);
                }
                startWindow++;
                currentLength--;

            }

            maxLength =  max(maxLength, currentLength);
        }

        return maxLength;
    }
};
