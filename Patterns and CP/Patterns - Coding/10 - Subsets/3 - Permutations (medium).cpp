Given a set of distinct numbers, find all of its permutations.

Permutation is defined as the re-arranging of the elements of the set. For example, {1, 2, 3} has the following six permutations:

{1, 2, 3}
{1, 3, 2}
{2, 1, 3}
{2, 3, 1}
{3, 1, 2}
{3, 2, 1}
If a set has ‘n’ distinct elements it will have n!n! permutations.

Example 1:

Input: [1,3,5]
Output: [1,3,5], [1,5,3], [3,1,5], [3,5,1], [5,1,3], [5,3,1]


static List<List<Integer>> findPermutations(int[] nums) {
  List<List<Integer>> result = new ArrayList<>();
  Queue<List<Integer>> permutations = new LinkedList<>();
  permutations.add(new ArrayList<>());
  for (int currentNumber : nums) {
    // we will take all existing permutations and add the current number to create new permutations
    int n = permutations.size();
    for (int i = 0; i < n; i++) {
      List<Integer> oldPermutation = permutations.poll();
      // create a new permutation by adding the current number at every position
      for (int j = 0; j <= oldPermutation.size(); j++) {
        List<Integer> newPermutation = new ArrayList<Integer>(oldPermutation);
        newPermutation.add(j, currentNumber);
        if (newPermutation.size() == nums.length)
          result.add(newPermutation);
        else
          permutations.add(newPermutation);
      }
    }
  }
  return result;
}

Time complexity #
We know that there are a total of N! permutations of a set with ‘N’ numbers. In the algorithm above, we are iterating through all of these permutations with the help of the two ‘for’ loops. In each iteration, we go through all the current permutations to insert a new number in them on line 17 (line 23 for C++ solution). To insert a number into a permutation of size ‘N’ will take O(N), which makes the overall time complexity of our algorithm O(N*N!).

Space complexity #
All the additional space used by our algorithm is for the result list and the queue to store the intermediate permutations. If you see closely, at any time, we don’t have more than N! permutations between the result list and the queue. Therefore the overall space complexity to store N! permutations each containing N elements will be O(N*N!).
