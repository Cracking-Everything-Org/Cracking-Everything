class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> ht;
        for (int i = 0; i < nums.size(); i++) {
            if (ht.find(nums[i]) != ht.end()) {
                ht[nums[i]]++;
            } else {
                ht[nums[i]] = 1;
            }
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> minHeap;

        for (auto entry : ht) {
            minHeap.push(make_pair(entry.second, entry.first));
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        while (!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
    }


    struct compare {
        bool operator()(pair<int,int>& p, pair<int,int>& q) {
            return p.first > q.first;
        }
    };
};
