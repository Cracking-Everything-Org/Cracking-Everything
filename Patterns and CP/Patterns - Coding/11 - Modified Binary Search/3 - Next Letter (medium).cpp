Problem Statement #
Given an array of lowercase letters sorted in ascending order, find the smallest letter in the given array greater than a given ‘key’.

Assume the given array is a circular list, which means that the last letter is assumed to be connected with the first letter. This also means that the smallest letter in the given array is greater than the last letter of the array and is also the first letter of the array.

Write a function to return the next letter of the given ‘key’.

Example 1:

Input: ['a', 'c', 'f', 'h'], key = 'f'
Output: 'h'
Explanation: The smallest letter greater than 'f' is 'h' in the given array.
Example 2:

Input: ['a', 'c', 'f', 'h'], key = 'b'
Output: 'c'
Explanation: The smallest letter greater than 'b' is 'c'.
Example 3:

Input: ['a', 'c', 'f', 'h'], key = 'm'
Output: 'a'
Explanation: As the array is assumed to be circular, the smallest letter greater than 'm' is 'a'.
Example 4:

Input: ['a', 'c', 'f', 'h'], key = 'h'
Output: 'a'
Explanation: As the array is assumed to be circular, the smallest letter greater than 'h' is 'a'.

char searchNextLetter(const vector<char>& letters, char key) {
  int n = letters.size();
  if (key < letters[0] || key > letters[n - 1]) {
    return letters[0];
  }

  int start = 0, end = n - 1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (key < letters[mid]) {
      end = mid - 1;
    } else {  // if (key >= letters[mid]) {
      start = mid + 1;
    }
  }
  // since the loop is running until 'start <= end', so at the end of the
  // while loop, 'start == end+1'
  return letters[start % n];
}


Time complexity #
Since, we are reducing the search range by half at every step, this means that the time complexity of our algorithm will be O(logN) where ‘N’ is the total elements in the given array.

Space complexity #
The algorithm runs in constant space O(1).
