Given a list of non-overlapping intervals sorted by their start time, insert a given interval at the correct position and merge all necessary intervals to produce a list that has only mutually exclusive intervals.

Input: Intervals=[[1,3], [5,7], [8,12]], New Interval=[4,6]
Output: [[1,3], [4,7], [8,12]]
Explanation: After insertion, since [4,6] overlaps with [5,7], we merged them into one [4,7].

Input: Intervals=[[1,3], [5,7], [8,12]], New Interval=[4,10]
Output: [[1,3], [4,12]]
Explanation: After insertion, since [4,10] overlaps with [5,7] & [8,12], we merged them into [4,12].

Input: Intervals=[[2,3],[5,7]], New Interval=[1,4]
Output: [[1,4], [5,7]]
Explanation: After insertion, since [1,4] overlaps with [2,3], we merged them into one [1,4].

vector<Interval> insert(const vector<Interval> &intervals, Interval newInterval) {
    if (intervals.empty() || intervals.empty()) {
      return vector<Interval>{newInterval};
    }

    vector<Interval> mergedIntervals;

    int i = 0;
    // skip (and add to output) all intervals that come before the 'newInterval'
    while (i < intervals.size() && intervals[i].end < newInterval.start) {
      mergedIntervals.push_back(intervals[i++]);
    }

    // merge all intervals that overlap with 'newInterval'
    while (i < intervals.size() && intervals[i].start <= newInterval.end) {
      newInterval.start = min(intervals[i].start, newInterval.start);
      newInterval.end = max(intervals[i].end, newInterval.end);
      i++;
    }

    // insert the newInterval
    mergedIntervals.push_back(newInterval);

    // add all the remaining intervals to the output
    while (i < intervals.size()) {
      mergedIntervals.push_back(intervals[i++]);
    }

    return mergedIntervals;
  }

Time complexity #
As we are iterating through all the intervals only once, the time complexity of the above algorithm is O(N), where ‘N’ is the total number of intervals.

Space complexity #
The space complexity of the above algorithm will be O(N) as we need to return a list containing all the merged intervals.
