class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size());

        answer[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            answer[i] = nums[i-1] * answer[i-1];
        }

        int R = 1;
        for (int j = nums.size() - 1; j >= 0; j--) {
            answer[j] = answer[j] * R;
            R *= nums[j];
        }
        return answer;
    }
};


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prods(nums.size(),0);
        int leftProd = 1;
        int rightProd = 1;
        int countZeros = 0;

        int rPWZ = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                countZeros++;
                if (countZeros == 2) {
                    return prods;
                }
            } else rPWZ *= nums[i];
            rightProd *= nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                prods[i] = rPWZ;
            } else {
                rightProd /= nums[i];
                prods[i] = rightProd * leftProd;
                leftProd *= nums[i];
            }
        }
        return prods;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        if (!nums.size()) return result;
        
        vector<int> fromLeft(nums.size(), 0);
        fromLeft[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            fromLeft[i] = fromLeft[i - 1] * nums[i - 1];
        }
        
        vector<int> fromRight(nums.size(), 0);
        fromRight[nums.size() - 1] = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            fromRight[i] = fromRight[i + 1] * nums[i + 1];
        }
        
        for (int i = 0; i < nums.size(); i++) {
            result[i] = fromLeft[i] * fromRight[i];
        }
        
        return result;
    }
};