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
