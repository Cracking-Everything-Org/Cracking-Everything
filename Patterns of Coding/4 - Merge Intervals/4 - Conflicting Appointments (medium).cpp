Given an array of intervals representing ‘N’ appointments, find out if a person can attend all the appointments.

Appointments: [[1,4], [2,5], [7,9]]
Output: false
Explanation: Since [1,4] and [2,5] overlap, a person cannot attend both of these appointments.

Appointments: [[6,7], [2,4], [8,12]]
Output: true
Explanation: None of the appointments overlap, therefore a person can attend all of them.

Appointments: [[4,5], [2,3], [3,6]]
Output: false
Explanation: Since [4,5] and [3,6] overlap, a person cannot attend both of these appointments.

bool canAttendAllAppointments(vector<Interval>& intervals) {
    // TODO: Write your code here
    if(intervals.size()<2) return true;
    sort(intervals.begin(), intervals.end(),
         [](const Interval &x, const Interval &y) { return x.start < y.start; });
    for(int i=1; i<intervals.size(); i++){
      if(intervals[i-1].end >= intervals[i].start) return false;
    }
    return true;
  }

  Time complexity #
  The time complexity of the above algorithm is O(N*logN), where ‘N’ is the total number of appointments. Though we are iterating the intervals only once, our algorithm will take O(N * logN) since we need to sort them in the beginning.

  Space complexity #
  The space complexity of the above algorithm will be O(N), which we need for sorting.
