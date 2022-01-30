class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        // Uso un vector de vectores para poder setearle un tamaño fijo
        vector<vector<int>> memo;
		memo.resize(2005, vector<int>(25, -1));
        return findWays(memo, nums, 0, 0, S);
    }

    int findWays(vector<vector<int>>& memo, vector<int>& nums, int index, int current, int S) {
        // necesito este caso base para que no se me vaya al carajo
	if (current < -1000 || current > 1000) return 0;
        if (index == nums.size()) {
            if (current == S) {
                return 1;
            } else {
                return 0;
            }
        }
        if (memo[1000 + current][index] != -1) {
            return memo[1000 + current][index];
        }
        int add = findWays(memo, nums, index + 1, current + nums[index], S);
        int substract = findWays(memo, nums, index + 1, current - nums[index], S);
        memo[1000 + current][index] = add + substract;
        return add + substract;
    }
};
