For ‘K’ employees, we are given a list of intervals representing the working hours of each employee. Our goal is to find out if there is a free interval that is common to all employees. You can assume that each list of employee working hours is sorted on the start time.

Input: Employee Working Hours=[[[1,3], [5,6]], [[2,3], [6,8]]]
Output: [3,5]
Explanation: Both the employess are free between [3,5].

Input: Employee Working Hours=[[[1,3], [9,12]], [[2,4]], [[6,8]]]
Output: [4,6], [8,9]
Explanation: All employess are free between [4,6] and [8,9].

Input: Employee Working Hours=[[[1,3]], [[2,4]], [[3,5], [7,9]]]
Output: [5,7]
Explanation: All employess are free between [5,7].

vector<Interval> findEmployeeFreeTime(const vector<vector<Interval>> &schedule) {
  vector<Interval> result;
  if (schedule.empty()) {
    return result;
  }

  // PriorityQueue to store one interval from each employee
  priority_queue<pair<Interval, pair<int, int>>, vector<pair<Interval, pair<int, int>>>,
                 startCompare>
      minHeap;

  // insert the first interval of each employee to the queue
  for (int i = 0; i < schedule.size(); i++) {
    minHeap.push(make_pair(schedule[i][0], make_pair(i, 0)));
  }

  Interval previousInterval = minHeap.top().first;
  while (!minHeap.empty()) {
    auto queueTop = minHeap.top();
    minHeap.pop();
    // if previousInterval is not overlapping with the next interval, insert a free interval
    if (previousInterval.end < queueTop.first.start) {
      result.push_back({previousInterval.end, queueTop.first.start});
      previousInterval = queueTop.first;
    } else {  // overlapping intervals, update the previousInterval if needed
      if (previousInterval.end < queueTop.first.end) {
        previousInterval = queueTop.first;
      }
    }

    // if there are more intervals available for the same employee, add their next interval
    vector<Interval> employeeSchedule = schedule[queueTop.second.first];
    if (employeeSchedule.size() > queueTop.second.second + 1) {
      minHeap.push(make_pair(employeeSchedule[queueTop.second.second + 1],
                             make_pair(queueTop.second.first, queueTop.second.second + 1)));
    }
  }

  return result;
}

Time complexity #
The time complexity of the above algorithm is O(N*logK), where ‘N’ is the total number of intervals and ‘K’ is the total number of employees. This is due to the fact that we are iterating through the intervals only once (which will take O(N)), and every time we process an interval, we remove (and can insert) one interval in the Min Heap, (which will take O(logK)). At any time the heap will not have more than ‘K’ elements.

Space complexity #
The space complexity of the above algorithm will be O(K) as at any time the heap will not have more than ‘K’ elements.
