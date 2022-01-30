class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> frequency;
        unordered_map<int, int> tails;

        for (int i = 0; i < nums.size(); i++) {
            if (frequency.find(nums[i]) != frequency.end()) {
                frequency[nums[i]]++;
            } else {
                frequency[nums[i]] = 1;
            }
        }

        for (int x : nums) {
            if (frequency.find(x) != frequency.end() && frequency[x] == 0) {
                continue;
            }
            // al ser greedy trato de attachear primero
            if (tails.find(x) != tails.end() && tails[x] > 0) {
                tails[x]--;
                if (tails.find(x + 1) != tails.end()) {
                    tails[x + 1]++;
                } else {
                    tails[x + 1] = 1;
                }
            } else if (frequency.find(x + 1) != frequency.end() && frequency[x + 1] > 0
                       && frequency.find(x + 2) != frequency.end() && frequency[x + 2] > 0) {
                frequency[x + 1]--;
                frequency[x + 2]--;
                if (tails.find(x + 3) != tails.end()) {
                    tails[x + 3]++;
                } else {
                    tails[x + 3] = 1;
                }
            } else {
                return false;
            }
            frequency[x]--;
        }
        return true;
    }
};
