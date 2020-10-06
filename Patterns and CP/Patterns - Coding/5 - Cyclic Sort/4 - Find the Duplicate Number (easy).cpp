We are given an unsorted array containing ‘n+1’ numbers taken from the range 1 to ‘n’. The array has only one duplicate but it can be repeated multiple times. Find that duplicate number without using any extra space. You are, however, allowed to modify the input array.

Input: [1, 4, 4, 3, 2]
Output: 4

Input: [2, 1, 3, 3, 5, 4]
Output: 3

Input: [2, 4, 1, 4, 4]
Output: 4

int findNumber(vector<int> &nums) {
  // TODO: Write your code here
  int i=0;
  while(i<nums.size()){
    if(nums[i] != nums[nums[i] - 1]){
      swap(nums[i], nums[nums[i] - 1]);
    } else {
      if(nums[i] != i + 1) return nums[i];
      i++;
    }
  }
  return -1;
}

Time complexity #
The time complexity of the above algorithm is O(n).

Space complexity #
The algorithm runs in constant space O(1) but modifies the input array.
