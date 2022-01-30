class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> v(128, 0);
        for (auto c:t) v[c]++;
        int start = 0, end = 0, counter = t.size();
        int minStart = 0, minLen = INT_MAX;
        while (end < s.size()) {
            if (v[s[end]] > 0) 
                counter--;
            v[s[end]]--;
            end++;
            while (counter == 0) {
                if (end - start < minLen) {
                    minStart = start;
                    minLen = end - start;
                }
                v[s[start]]++;
                if (v[s[start]] > 0) 
                    counter++;
                start++;
            }
        }
        if (minLen != INT_MAX)
            return s.substr(minStart, minLen);
        
        return "";
    }