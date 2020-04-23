class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;

        sort(points.begin(), points.end(),
         [](const vector<int> &x, const vector<int> &y) { return x[1] < y[1]; });

        int arrows = 1;
        int currentStart;
        int currentEnd;
        int end = points[0][1];
        for (auto p : points) {
            currentStart = p[0];
            currentEnd = p[1];
            // si ya pasé de rango, necesito otra flecha
            if (end < currentStart) {
                arrows++;
                end = currentEnd;
            }
        }
        return arrows;
      }
};
