We are given an unsorted array containing ‘n’ numbers taken from the range 1 to ‘n’. The array originally contained all the numbers from 1 to ‘n’, but due to a data error, one of the numbers got duplicated which also resulted in one number going missing. Find both these numbers.

Input: [3, 1, 2, 5, 2]
Output: [2, 4]
Explanation: '2' is duplicated and '4' is missing.

Input: [3, 1, 2, 3, 6, 4]
Output: [3, 5]
Explanation: '3' is duplicated and '5' is missing.

vector<int> findNumbers(vector<int> &nums) {
  // TODO: Write your code here
  int i=0;
  while(i< nums.size()){
    if(nums[i] != nums[nums[i] - 1]){
      swap(nums[i], nums[nums[i] - 1]);
    } else {
      i++;
    }
  }
  for(int i=0; i<nums.size(); i++){
    if(nums[i] != i + 1) return vector<int>{nums[i], i + 1};
  }
  return vector<int>{-1, -1};
}

Time complexity #
The time complexity of the above algorithm is O(n).

Space complexity #
The algorithm runs in constant space O(1).
