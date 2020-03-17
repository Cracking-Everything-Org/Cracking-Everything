class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {

        unordered_map<char,int> frequencyMap;
        int longestLen = 0;

        int startPointer = 0;


        for (int endPointer = 0; endPointer < s.length(); endPointer++) {
            frequencyMap[s[endPointer]]++;

            if (frequencyMap.size() <= k) {
                longestLen = max(longestLen, endPointer - startPointer + 1);
            }

            while (frequencyMap.size() > k) {
                frequencyMap[s[startPointer]]--;
                if (frequencyMap[s[startPointer]] == 0) {
                    frequencyMap.erase(s[startPointer]);
                }
                startPointer++;
            }

        }
        return longestLen;
    }
};
