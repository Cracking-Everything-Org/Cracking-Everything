class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> collisionTimes(n, -1);
        stack<int> stk;
        
        for (int i = n - 1; i >= 0; i--) {
            // pop the cars with greater or equal speed. We will never be able to reach them
            while (!stk.empty() && cars[i][1] <= cars[stk.top()][1]) 
                stk.pop();
            
            // now I will be able to catch the cars but how many?
            // if my next car collides its next earlier than current collides the next then the current car will collide with both these cars
            while (!stk.empty()) {
                int current = stk.top();
                double time = (double) (cars[current][0] - cars[i][0]) / (cars[i][1] - cars[current][1]);
                if (time <= collisionTimes[current] || collisionTimes[current] < 0) {
                    collisionTimes[i] = time;
                    break;
                }
                stk.pop();
            }
            
            stk.push(i);
        }
        
        return collisionTimes;
    }
};