class Point {
 public:
  int x = 0;
  int y = 0;

  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }

  int distFromOrigin() const {
    // ignoring sqrt
    return (x * x) + (y * y);
  }
};

class KClosestPointsToOrigin {
 public:
  static vector<Point> findClosestPoints(const vector<Point>& points, int k) {
    vector<Point> result;
    priority_queue<Point, vector<Point>, compare> maxHeap;

    for (int i = 0; i < points.size(); i++) {
      maxHeap.push(points[i]);
      if (maxHeap.size() > k) {
        maxHeap.pop();
      }
    }

    while (!maxHeap.empty()) {
      result.push_back(maxHeap.top());
      maxHeap.pop();
    }

    return result;
  }

  struct compare {
    bool operator()(Point& a, Point& b) {
      return a.distFromOrigin() < b.distFromOrigin();
    }
  };

};