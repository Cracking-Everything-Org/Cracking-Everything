class Solution {
public:
    // SLIDING WINDOW
    int maxScore(vector<int>& cardPoints, int k) {
        if (cardPoints.size() < k) {
            return -1;
        }
        vector<int> candidates;
        int size = cardPoints.size() - 1;
        for (int i = size - k + 1; i <= size; i++) {
            candidates.push_back(cardPoints[i]);
        }
        for (int i = 0; i < k; i++) {
            candidates.push_back(cardPoints[i]);
        }
        int maxPoints = INT_MIN;
        int points = 0;
        int startWindow = 0;
        for (int endWindow = 0; endWindow < candidates.size(); endWindow++) {
            points += candidates[endWindow];
            if (endWindow - startWindow + 1 >= k) {
                maxPoints = maxPoints < points ? points : maxPoints;
                points -= candidates[startWindow];
                startWindow++;
            }
        }
        return maxPoints;
    }
};
