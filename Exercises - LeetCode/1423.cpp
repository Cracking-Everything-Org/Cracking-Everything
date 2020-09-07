class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<vector<int>> memo(k + 1, vector<int>(k + 1, -1));
        return getMaxScore(cardPoints, k, 0, cardPoints.size() - 1, 0, memo);
    }

    int getMaxScore(vector<int>& cardPoints, int k, int left, int right, int points, vector<vector<int>>& memo) {
        // ya no tengo como retirar cartas
        if (k == 0) {
            return points;
        }
        // si me voy de rango ya no es valido, "You have to take exactly k cards"
        if (left > cardPoints.size() - 1 || right < 0) {
            return INT_MIN;
        }
        // si ya conozco el valor para esa combinacion de left/right
        if (memo[left][cardPoints.size() - 1 - right] != -1) {
            return memo[left][cardPoints.size() - 1 - right];
        }

        int ans = max( getMaxScore(cardPoints, k-1, left + 1, right, points + cardPoints[left], memo) , getMaxScore(cardPoints, k-1, left, right - 1, points + cardPoints[right], memo) );
        return memo[left][cardPoints.size() - 1 - right] = ans;
    }
};
