Given an unsorted array containing numbers, find the smallest missing positive number in it.

Input: [-3, 1, 5, 4, 2]
Output: 3
Explanation: The smallest missing positive number is '3'

Input: [3, -2, 0, 1, 2]
Output: 4

Input: [3, 2, 5, 1]
Output: 4

int findNumber(vector<int> &nums) {
  // TODO: Write your code here
  int i = 0;
  while(i < nums.size()){
    if(nums[i] != nums[nums[i] - 1] && nums[i] > 0 && nums[i] < nums.size()){
      swap(nums[i], nums[nums[i] - 1]);
    } else {
      i++;
    }
  }

  for(int i=0; i< nums.size(); i++){
    if(nums[i] != i + 1) return i+1;
  }
  return -1;
}

Time complexity #
The time complexity of the above algorithm is O(n).

Space complexity #
The algorithm runs in constant space O(1).
