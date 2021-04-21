class Interval {
 public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class InsertInterval {
 public:
  static vector<Interval> insert(const vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> result;

    int i = 0;
    while (i < intervals.size() && newInterval.start < intervals[i].end) {
      result.push_back(intervals[i]);
      i++;
    }

    while (i < intervals.size() && newInterval.end > intervals[i].start) {
      newInterval.start = min(newInterval.start, intervals[i].start);
      newInterval.end = max(newInterval.end, intervals[i].end);
      i++;
    }

    result.push_back(newInterval);

    while (i < intervals.size()) {
      result.push_back(intervals[i]);
      i++;
    }

    return result;
  }
};
