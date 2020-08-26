class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        int median_pos = k - k / 2 - 1;
        vector<double> res(size - k + 1);

        multiset<int> s(nums.begin(), nums.begin() + k);
        auto it = next(s.begin(), median_pos);

        // i va a ser mi endWindow
        for (auto i = k; i <= size; ++i) {
            res[i - k] = ((double)*it + (k % 2 != 0 ? *it : *next(it))) / 2;
            if (i < size) {
                // magic numbers (instead of enum) for brevity. INT_MAX means to retrace the iterator from the beginning.
                int repos_it = INT_MAX;
                if (k > 2) {
                    // if inserted or removed item equals to the current median, we need to retrace.
                    // we do not know which exact element will be removed/inserted, and we cannot compare multiset iterators.
                    // otherwise, we can keep or increment/decrement the current median iterator.
                    if ((nums[i - k] < *it && nums[i] < *it) || (nums[i - k] > *it && nums[i] > *it)) repos_it = 0;
                    else if (nums[i - k] < *it && nums[i] > *it) repos_it = 1; // advance forward.
                    else if (nums[i - k] > *it && nums[i] < *it) repos_it = -1; // advance backward.
                }
                s.insert(nums[i]);
                s.erase(s.find(nums[i - k]));

                if (repos_it == INT_MAX) it = next(s.begin(), median_pos);
                else if (repos_it == 1) it++;
                else if (repos_it == -1) it--;
            }
        }
        return res;
    }
};

/*
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medians;
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int startWindow = 0;
        for (int endWindow = 0; endWindow < nums.size(); endWindow++) {
            if (maxHeap.empty() || maxHeap.top() > nums[endWindow]) {
                maxHeap.push(nums[endWindow]);
            } else {
                minHeap.push(nums[endWindow]);
            }
            if (maxHeap.size() + minHeap.size() >= k) {
                calculateMedian(minHeap, maxHeap, medians);
                // necesito extender priority_queue y redefinir el metodo de remover
                removeElement(nums[startWindow], minHeap, maxHeap);
                balance(minHeap, maxHeap);
                startWindow++;
            }
        }
        return medians;
    }

    void calculateMedian(priority_queue<int, vector<int>, greater<int>>& minHeap, priority_queue<int>& maxHeap, vector<double>& medians) {
        double median = 0;
        if (maxHeap.size() == minHeap.size()) {
            median = ((double)maxHeap.top() + (double)minHeap.top()) / 2;
        } else {
            median = maxHeap.top();
        }
        medians.push_back(median);
    }

    void balance(priority_queue<int, vector<int>, greater<int>>& minHeap, priority_queue<int>& maxHeap) {
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
};
*/
