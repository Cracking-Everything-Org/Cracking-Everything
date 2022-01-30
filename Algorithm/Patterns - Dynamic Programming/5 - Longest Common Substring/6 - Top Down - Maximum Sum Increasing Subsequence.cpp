public int findMSIS(int[] nums) {
  Map<String, Integer> dp = new HashMap<>();  
  return findMSISRecursive(dp, nums, 0, -1, 0);
}

private int findMSISRecursive(Map<String, Integer> dp, int[] nums, int currentIndex, int previousIndex, int sum) {
  if(currentIndex == nums.length)
    return sum;

  String subProblemKey = currentIndex + "-" + previousIndex + "-" + sum;
  if(!dp.containsKey(subProblemKey)) {
    // include nums[currentIndex] if it is larger than the last included number
    int s1 = sum;
    if(previousIndex == -1 || nums[currentIndex] > nums[previousIndex])
      s1 = findMSISRecursive(dp, nums, currentIndex+1, currentIndex, sum + nums[currentIndex]);

    // excluding the number at currentIndex
    int s2 = findMSISRecursive(dp, nums, currentIndex+1, previousIndex, sum);
    dp.put(subProblemKey, Math.max(s1, s2));
  }

  return dp.get(subProblemKey);
}
