public int findLISLength(int[] nums) {
    return findLISLengthRecursive(nums, 0, -1);
}

private int findLISLengthRecursive(int[] nums, int currentIndex, int previousIndex) {
  if(currentIndex == nums.length)
    return 0;

  // include nums[currentIndex] if it is larger than the last included number
  int c1 = 0;
  if(previousIndex == -1 || nums[currentIndex] > nums[previousIndex])
    c1 = 1 + findLISLengthRecursive(nums, currentIndex+1, currentIndex);

  // excluding the number at currentIndex
  int c2 = findLISLengthRecursive(nums, currentIndex+1, previousIndex);

  return Math.max(c1, c2);
}
