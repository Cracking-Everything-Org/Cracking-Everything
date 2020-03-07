We are given an unsorted array containing ‘n’ numbers taken from the range 1 to ‘n’. The array has some duplicates, find all the duplicate numbers without using any extra space.

Input: [3, 4, 4, 5, 5]
Output: [4, 5]

Input: [5, 4, 7, 2, 3, 5, 3]
Output: [3, 5]

vector<int> findNumbers(vector<int> &nums) {
  vector<int> duplicateNumbers;
  // TODO: Write your code here
  int i=0;
  while(i<nums.size()){
    if(nums[i] != nums[nums[i] - 1]){
      swap(nums[i], nums[nums[i] - 1]);
    } else {
      if(nums[i] != i + 1){
        duplicateNumbers.push_back(nums[i]);
      }
      i++;
    }
  }
  return duplicateNumbers;
}

Time complexity #
The time complexity of the above algorithm is O(n).

Space complexity #
Ignoring the space required for storing the duplicates, the algorithm runs in constant space O(1).
