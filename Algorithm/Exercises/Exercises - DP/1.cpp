/*
1. Given an array, write a recursive function to check if the elements of array are in sequence.

Input = [2,3,4,5,6,7], Output = true
Input = [2,4,5,6,7], Output = false, because 3 is missing in the sequence

ins(list, n) = ins(list, n - 1) if list[n] == list[n-1] + 1
accumulative(list, 0) = true
*/

bool isInSequence(vector<int>& list, int index) {
  return (index == 0 || (list[index] == list[index - 1] + 1 && isInSequence(list, index - 1));
}
