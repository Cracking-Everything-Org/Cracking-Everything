class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string, int> ht;

        for (int i = 0; i < words.size(); i++) {
            if (ht.find(words[i]) != ht.end()) {
                ht[words[i]]++;
            } else {
                ht[words[i]] = 1;
            }
        }

        priority_queue<pair<int,string>, vector<pair<int, string>>, compare> minHeap;

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

        reverse(ans.begin(), ans.end());
        return ans;
    }

    struct compare {
        bool operator()(pair<int,string>& p, pair<int,string>& q) {
            return p.first == q.first ? p.second < q.second : p.first > q.first;
        }
    };
};
