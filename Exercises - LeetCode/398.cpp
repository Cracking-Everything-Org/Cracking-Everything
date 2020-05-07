class Solution {
public:

    // RESERVOIR SAMPLING

    //     prob de elegir el primero
    //                   prob de no elegir siguientes
    //    formula -> (1/i) * (1 - 1/i+1) * (1 - 1/i+2) * ... * (1 - 1/i+n)

    // simplifing -> (1/i) * (i+1/i+1  + 1/i+1) * ... * (i+n/i+n - 1/i+n)

    // simplifing -> (1/i) * (i/i+1) * (i+1/i+2) *... * (n-1/n)

    // after cancel terms  -> (1/n)

    vector<int> nums;

    Solution(vector<int>& nums) {
        this->nums = nums;
    }

    int pick(int target) {
        int result = 0, counter = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                if(rand() % counter == 0) { // si counter 2, esto me devuelve 0 o 1, (sumulando el 1/2)
                    result = i;
                }
                counter++;
            }
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
