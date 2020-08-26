class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        queue<vector<int>> permutations;
        permutations.push(vector<int>());
        for (auto currentNumber : nums) {
            int n = permutations.size();

            for (int i = 0; i < n; i++) {
                vector<int> oldPermutation = permutations.front();
                permutations.pop();

                for (int j = 0; j <= oldPermutation.size(); j++) {
                    vector<int> newPermutation(oldPermutation);
                    newPermutation.insert(newPermutation.begin() + j, currentNumber);

                    if (newPermutation.size() == nums.size()) {
                        result.push_back(newPermutation);
                    } else {
                        permutations.push(newPermutation);
                    }
                }
            }
        }
        return result;
    }
};
