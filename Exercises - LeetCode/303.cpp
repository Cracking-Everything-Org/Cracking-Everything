class NumArray {
public:
    vector<int> num;

    NumArray(vector<int>& nums) {
        num = nums;
    }

    int sumRange(int i, int j) {
        int sum = 0;
        for (int k = i; k <= j; k++) {
            sum += num[k];
        }
        return sum;
    }
};
