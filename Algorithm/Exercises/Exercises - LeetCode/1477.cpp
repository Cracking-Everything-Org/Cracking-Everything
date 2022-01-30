class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        // PREFIX SUM
        int n = arr.size();
        vector<int> reversed (arr.rbegin(), arr.rend());
        vector<int> left = help(arr, target);
        vector<int> right = help(arr, target);
        reverse(right.begin(), right.end());
        int ans = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            ans = min(ans, left[i] + right[i + 1]);
        }
        return ans <= n ? ans : -1;
    }

    vector<int> help(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int, int> hm;
        hm[0] = -1;
        vector<int> ans(n, n + 1);
        vector<int> prefix(n, 0);
        for (int i = 0; i < n; i++) {
            int length = n + 1;
            prefix[i] = (i == 0 ? 0 : prefix[i - 1]) + arr[i];
            int required = prefix[i] - target;
            if (hm.find(required) != hm.end()) {
                length = i - hm[required];
            }
            hm[prefix[i]] = i;
            ans[i] = min(length, (i == 0 ? length : ans[i - 1]));
        }
        return ans;
    }

};
