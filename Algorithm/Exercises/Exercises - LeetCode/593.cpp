class Solution {
public:
    double dist(vector<int>& c1, vector<int>& c2) {
        int a = c1[0] - c2[0];
        int b = c1[1] - c2[1];
        return sqrt(a*a + b*b);
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = { p1, p2, p3, p4 };
        set<double> distances;
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                double distance = dist(points[i], points[j]);
                if (distance == 0) return false;
                distances.insert(distance);
            }
        }
        // distancia de una arista y de una diagonal
        return distances.size() == 2;
    }
};