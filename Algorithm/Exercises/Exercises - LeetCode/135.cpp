class Solution {
public:
    int candy(vector<int>& ratings) {
        int count = 0;
        vector<int> leftCandies (ratings.size(), 1);
        vector<int> rightCandies (ratings.size(), 1);
        for (int i = 1; i < ratings.size() ; i++) {
            if (ratings[i] > ratings[i-1]) {
                leftCandies[i] = leftCandies[i-1]+1;
            }
        }
        for (int i = ratings.size()-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                rightCandies[i] = rightCandies[i+1]+1;
            }
        }
        for (int i = 0; i < leftCandies.size(); i++) {
            count += max(leftCandies[i], rightCandies[i]);
        }
        return count;
    }
};
