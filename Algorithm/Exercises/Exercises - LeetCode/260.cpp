class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n1xn2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            n1xn2 ^= nums[i];
        }

        // get the rightmost bit that is '1'
        int rightmostSetBit = 1;
        while ((rightmostSetBit & n1xn2) == 0) {
          rightmostSetBit = rightmostSetBit << 1;
        }

        int num1 = 0, num2 = 0;
        for (int num : nums) {
          if ((num & rightmostSetBit) != 0) // the bit is set
            num1 ^= num;
          else // the bit is not set
            num2 ^= num;
        }
        return vector<int>{num1, num2};
    }
};
