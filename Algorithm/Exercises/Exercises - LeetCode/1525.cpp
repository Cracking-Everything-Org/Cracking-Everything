class Solution {
public:
    int numSplits(string s) { // Time: O(N) , Memory: O(1)
        int goodSplits = 0;
        vector<int> left(26);
        vector<int> right(26);
        
        for (auto c : s) {
            right[c - 'a']++;
        }
        
        for (auto c : s) {
            left[c - 'a']++;
            right[c - 'a']--;
            
            int distinctCharOnLeft = distinctChars(left);
            int distinctCharOnRight = distinctChars(right);
            
            if (distinctCharOnLeft == distinctCharOnRight) {
                goodSplits++;
            }
        }
        
        return goodSplits;
    }
    
    int distinctChars(vector<int> list) { // Time: O(1) , Memory: O(1)
        int totalDistinct = 0;
        
        for (auto frequency : list) {
            if (frequency != 0) {
                totalDistinct++;
            }
        }
        
        return totalDistinct;
    }
};