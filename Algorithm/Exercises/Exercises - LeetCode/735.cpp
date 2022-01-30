class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> toProcess;
        
        int i = 0;
        while (i < asteroids.size()) {
            if (asteroids[i] > 0) {
                toProcess.push(asteroids[i]);
            } else {
                while (!toProcess.empty() && toProcess.top() > 0 && toProcess.top() < abs(asteroids[i])) {
                    toProcess.pop();
                }
                
                if (!toProcess.empty() && toProcess.top() == abs(asteroids[i])) {
                    toProcess.pop();
                } else if (toProcess.empty() || toProcess.top() < 0) {
                    toProcess.push(asteroids[i]);
                }
            }
            i++;
        }
        
        vector<int> remainingAsteroids;
        
        while (!toProcess.empty()) {
            remainingAsteroids.push_back(toProcess.top());
            toProcess.pop();
        }
        
        reverse(remainingAsteroids.begin(), remainingAsteroids.end());
        
        return remainingAsteroids;
    }
};
