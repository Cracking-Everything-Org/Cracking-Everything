// slope (y2-y1) / (x2-x1)
// => (y2-y1) / (x2-x1) = (y3-y2) / (x3-x2) => (y2-y1) * (x3-x2) = (y3-y2) * (x2-x1)

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double xdiff = double(coordinates[1][0] - coordinates[0][0]);
        double ydiff = double(coordinates[1][1] - coordinates[0][1]);
        for (int i = 2; i < coordinates.size(); i++) {
            double currentXDiff = double(coordinates[i][0] - coordinates[i-1][0]);
            double currentYDiff = double(coordinates[i][1] - coordinates[i-1][1]);
            if (ydiff * currentXDiff != currentYDiff * xdiff) {
                return false;
            }
        }
        return true;
    }
};
