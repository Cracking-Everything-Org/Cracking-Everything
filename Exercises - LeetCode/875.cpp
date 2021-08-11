class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = pow(10, 9);
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (!possible(piles, h, mid)) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        return lo;
    }
    
    bool possible(vector<int>& piles, int h, int k) {
        int time = 0;
        for (int p : piles) {
            time += (p - 1) / k + 1;
        }
        return time <= h;
    }
};