class MedianFinder {
public:
    /** initialize your data structure here. */
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
    }

    void addNum(int num) {
        if (maxHeap.empty() || maxHeap.top() > num) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return ((double)maxHeap.top() + (double)minHeap.top()) / 2;
        } else {
            return maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
