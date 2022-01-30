/*
yi + yj + |xi - xj|  where |xi - xj| <= k 
yi + yj + xj - xi
(xj + yj) + (yi - xi)          where xj - xi <= k 
curr        prev
*/

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> maxHeap;
        
        //maxHeap.push({ yi - xi, xi });
        //maxHeap.push({ prev   , xi });
        maxHeap.push({ points[0][1] - points[0][0], points[0][0] });
        
        int res = INT_MIN;
        for (int j = 1; j < points.size(); j++) {
            
            //where xj - xi <= k 
            while (!maxHeap.empty() && points[j][0] - maxHeap.top().second > k)
                maxHeap.pop();
            
            if (!maxHeap.empty()) {
                int curr = points[j][0] + points[j][1];
                //res = max(res, curr + prev);
                res = max(res, curr + maxHeap.top().first);
            }
            
            //maxHeap.push({ yj - xj, xj });
            maxHeap.push({ points[j][1] - points[j][0], points[j][0] });
        }
        
        return res;
     }
};