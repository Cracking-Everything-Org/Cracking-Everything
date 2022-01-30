// Hello


 [4, 2, 10, 11, 7, 2, 3] --> -1


  [1, 2, 5, 100, 5, 3]
L  1 , 3, 8, 108, 113, 116
R 8,3


               8, 3





 [1, 2, 5, 3]  --> 2
  1, 3, 8, 11
  11, 10 , 8, 3

 -10, -7, 0 , 8



int equalPartition (vector<int> nums) {
    vector<int> leftAcc;
    vector<int> rightAcc;

    leftAcc[0] = nums[0];

    for  (int i = 1; i < nums.size(); i++) {
        leftAcc[i] = leftAcc[i-1] + nums[i];
    }

    rightAcc[nums.size()-1] = nums[nums.size()-1];

    for  (int j nums.size() - 2; j >= 0; i--) {
        rightAcc[j] = rightAcc[j+1] + nums[j];
    }

    vector<int> totals;
    for () {

    }
}
