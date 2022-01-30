class MovingAverage {
public:
    /** Initialize your data structure here. */
    vector<int> list;
    int nextAvailable = 0;
    int currentSum = 0;
    int elementsCounter = 0;
    int K = 0;

    MovingAverage(int size) {
        list.resize(size, INT_MIN);
        nextAvailable = 0;
        currentSum = 0;
        elementsCounter = 0;
        K = size;
    }

    double next(int val) {
        if (list[nextAvailable % list.size()] != INT_MIN) {
            currentSum -= list[nextAvailable % list.size()];
        }
        list[nextAvailable % list.size()] = val;
        currentSum += val;
        nextAvailable++;
        if (elementsCounter < K) elementsCounter++;
        return (double)currentSum / (double)elementsCounter;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
