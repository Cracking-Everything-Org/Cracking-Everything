Given an array of sorted numbers and a target sum, find a pair in the array whose sum is equal to the given target.

Write a function to return the indices of the two numbers (i.e. the pair) such that they add up to the given target.

Input: [1, 2, 3, 4, 6], target=6
Output: [1, 3]
Explanation: The numbers at index 1 and 3 add up to 6: 2+4=6

Input: [2, 5, 9, 11], target=11
Output: [0, 2]
Explanation: The numbers at index 0 and 2 add up to 11: 2+9=11

pair<int, int> search(const vector<int>& arr, int targetSum) {
    // TODO: Write your code here
    int firstPointer = 0;
    int secondPointer = arr.size()-1;
    while(firstPointer<secondPointer){
      if(arr[firstPointer] + arr[secondPointer] == targetSum){
        return make_pair(firstPointer, secondPointer);
      }else {
        if(arr[firstPointer] + arr[secondPointer] > targetSum){
          secondPointer--;
        } else {
          firstPointer++;
        }
      }
    }
    return make_pair(-1, -1);
  }

Time Complexity #
The time complexity of the above algorithm will be O(N), where ‘N’ is the total number of elements in the given array.

Space Complexity #
The algorithm runs in constant space O(1).
