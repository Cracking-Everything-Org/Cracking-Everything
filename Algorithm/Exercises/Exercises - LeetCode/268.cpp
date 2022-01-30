// bit manip - controla el overflow que puede causar al tratar de acceder a una posicion de un input muy grande
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int x1 = 1;
        for (int i = 2; i < n + 1; i++) {
            x1 = x1 ^ i;
        }

        int x2 = nums[0];
        for (int i = 1; i < n; i++) {
            x2 = x2 ^ nums[i];
        }

        return x1 ^ x2;
    }
};

/* cyclic sort

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] < nums.size()) {
                if (nums[i] != nums[nums[i]]) {
                    swap(nums[i], nums[nums[i]]);
                    i--;
                }
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) return i;
        }
        return nums.size();
    }
};
*/
