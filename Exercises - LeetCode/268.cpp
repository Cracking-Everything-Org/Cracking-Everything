class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //pensé en dos soluciones utilizando sort y hash table
        // la implementada utiliza la formula de Gauss
        //  n(n+1) / 2

        int expectedSum = nums.size()*(nums.size()+1)/2;
        int actualSum = 0;
        for(int i=0; i < nums.size(); i++){
            actualSum += nums[i];
        }
        return expectedSum-actualSum;
    }
};
