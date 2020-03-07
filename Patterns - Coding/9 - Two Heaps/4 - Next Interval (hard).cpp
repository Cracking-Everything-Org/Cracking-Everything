Given an array of intervals, find the next interval of each interval. In a list of intervals, for an interval ‘i’ its next interval ‘j’ will have the smallest ‘start’ greater than or equal to the ‘end’ of ‘i’.

Write a function to return an array containing indices of the next interval of each input interval. If there is no next interval of a given interval, return -1. It is given that none of the intervals have the same start point.

Example 1:

Input: Intervals [[2,3], [3,4], [5,6]]
Output: [1, 2, -1]
Explanation: The next interval of [2,3] is [3,4] having index ‘1’. Similarly, the next interval of [3,4] is [5,6] having index ‘2’. There is no next interval for [5,6] hence we have ‘-1’.

Example 2:

Input: Intervals [[3,4], [1,5], [4,6]]
Output: [2, -1, -1]
Explanation: The next interval of [3,4] is [4,6] which has index ‘2’. There is no next interval for [1,5] and [4,6].

public static int[] findNextInterval(Interval[] intervals) {
    int n = intervals.length;
    // heap for finding the maximum start
    PriorityQueue<Integer> maxStartHeap = new PriorityQueue<>(n, (i1, i2) -> intervals[i2].start - intervals[i1].start);
    // heap for finding the minimum end
    PriorityQueue<Integer> maxEndHeap = new PriorityQueue<>(n, (i1, i2) -> intervals[i2].end - intervals[i1].end);
    int[] result = new int[n];
    for (int i = 0; i < intervals.length; i++) {
      maxStartHeap.offer(i);
      maxEndHeap.offer(i);
    }

    // go through all the intervals to find each interval's next interval
    for (int i = 0; i < n; i++) {
      int topEnd = maxEndHeap.poll(); // let's find the next interval of the interval which has the highest 'end'
      result[topEnd] = -1; // defaults to -1
      if (intervals[maxStartHeap.peek()].start >= intervals[topEnd].end) {
        int topStart = maxStartHeap.poll();
        // find the the interval that has the closest 'start'
        while (!maxStartHeap.isEmpty() && intervals[maxStartHeap.peek()].start >= intervals[topEnd].end) {
          topStart = maxStartHeap.poll();
        }
        result[topEnd] = topStart;
        maxStartHeap.add(topStart); // put the interval back as it could be the next interval of other intervals
      }
    }
    return result;
  }

  Time complexity #
  The time complexity of our algorithm will be O(NlogN), where ‘N’ is the total number of intervals.

  Space complexity #
  The space complexity will be O(N) because we will be storing all the intervals in the heaps.
