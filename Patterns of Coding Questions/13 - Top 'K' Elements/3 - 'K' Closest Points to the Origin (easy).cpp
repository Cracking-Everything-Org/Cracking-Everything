Given an array of points in the a 2D2D plane, find ‘K’ closest points to the origin.

Example 1:

Input: points = [[1,2],[1,3]], K = 1
Output: [[1,2]]
Explanation: The Euclidean distance between (1, 2) and the origin is sqrt(5).
The Euclidean distance between (1, 3) and the origin is sqrt(10).
Since sqrt(5) < sqrt(10), therefore (1, 2) is closer to the origin.
Example 2:

Input: point = [[1, 3], [3, 4], [2, -1]], K = 2
Output: [[1, 3], [2, -1]]


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

  const bool operator<(const Point& p) { return p.distFromOrigin() > this->distFromOrigin(); }
};

class KClosestPointsToOrigin {
 public:
  static vector<Point> findClosestPoints(const vector<Point>& points, int k) {
    // put first 'k' points in the vector
    vector<Point> maxHeap(points.begin(), points.begin() + k);
    make_heap(maxHeap.begin(), maxHeap.end());

    for (int i = k; i < points.size(); i++) {
      if (points[i].distFromOrigin() < maxHeap.front().distFromOrigin()) {
        pop_heap(maxHeap.begin(), maxHeap.end());
        maxHeap.pop_back();
        maxHeap.push_back(points[i]);
        push_heap(maxHeap.begin(), maxHeap.end());
      }
    }

    return maxHeap;
  }
};


Time complexity #
The time complexity of this algorithm is (N*logK) as we iterating all points and pushing them into the heap.

Space complexity #
The space complexity will be O(K) because we need to store ‘K’ point in the heap.
