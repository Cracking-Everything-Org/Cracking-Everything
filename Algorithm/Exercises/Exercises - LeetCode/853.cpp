class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (!n) return 0;
        
        vector<pair<int, double>> finishTime;
        for (int i = 0 ; i < n; i++) {
            finishTime.push_back({-position[i], (double)(target - position[i]) / (double)speed[i]});
        }
        
        sort(finishTime.begin(), finishTime.end());
        
        int result = 0;
        double time = 0;
        for (int i = 0; i < n; i++) {
            if (finishTime[i].second > time) {
                time = finishTime[i].second;
                result++;
            }
        }
        
        return result; 
    }
};