using namespace std;

#include <iostream>
#include <queue>
#include <vector>

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
  struct compare {
    bool operator()(const Point &x, const Point &y) {
      return x.distFromOrigin() < y.distFromOrigin();
    }
  };

 public:
  static vector<Point> findClosestPoints(const vector<Point>& points, int k) {
    vector<Point> result;
    priority_queue<Point, vector<Point>, compare> minHeap;

    for (Point point : points) {
      minHeap.push(point);
      if (minHeap.size() > k) {
        minHeap.pop();
      }
    }

    while (!minHeap.empty()) {
      result.push_back(minHeap.top());
      minHeap.pop();
    }

    return result;
  }
};

int main(int argc, char* argv[]) {
  vector<Point> maxHeap = KClosestPointsToOrigin::findClosestPoints({{1, 3}, {3, 4}, {2, -1}}, 2);
  cout << "Here are the k points closest the origin: ";
  for (auto p : maxHeap) {
    cout << "[" << p.x << " , " << p.y << "] ";
  }
}

