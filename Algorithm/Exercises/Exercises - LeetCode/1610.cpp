class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) { // Time: O(points), Space: O(points)
        vector<double> sortedPoints;
        int sameLocationPoints = 0;
        
        for (auto point : points) {
            if (point[0] == location[0] && point[1] == location[1]) {
                sameLocationPoints++;
            }
            else { // MATH magica para poder ordenar luego
                double ang = atan2(point[1] - location[1], point[0] - location[0]) * 180.0 / M_PI;
                if (ang < 0) {
                    ang += 360;
                }
                sortedPoints.push_back(ang);
            }
        }
        
        sort(sortedPoints.begin(), sortedPoints.end());
        int n = sortedPoints.size();   
        int start = 0; 
        int maximumVisiblePoints = 0;
        
        for (int i = 0; i < n; i++) {
            sortedPoints.push_back(sortedPoints[i] + 360);
        }
        
        // SLIDING WINDOW
        for (int end = 0; end < sortedPoints.size(); end++) {
            while (sortedPoints[end] - sortedPoints[start] > angle) {
                start++;
            }
            
            maximumVisiblePoints = max(maximumVisiblePoints, end - start + 1);
        }
        return maximumVisiblePoints + sameLocationPoints;
    }
};