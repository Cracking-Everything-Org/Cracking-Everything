class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> intersections;
        int i = 0;
        int j = 0;
        
        while (i < firstList.size() && j < secondList.size()) {
            if ((firstList[i][0] >= secondList[j][0] && firstList[i][0] <= secondList[j][1]) || 
                (secondList[j][0] >= firstList[i][0] && secondList[j][0] <= firstList[i][1])) {
                vector<int> intersection(2, 0);
                intersection[0] = max(firstList[i][0], secondList[j][0]);
                intersection[1] = min(firstList[i][1], secondList[j][1]);
                intersections.push_back(intersection);
            }
            
            if (firstList[i][1] < secondList[j][1]) {
                i++;
            } else {
                j++;
            }
        }
        
        return intersections;
    }
};
