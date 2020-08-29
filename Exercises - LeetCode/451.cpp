class Solution {
public:
    string frequencySort(string s) {
        string result = "";
        priority_queue<pair<char, int>, vector<pair<char,int>>, compare> minHeap;
        unordered_map<char, int> hm;

        for (int i = 0; i < s.length(); i++) {
            if (hm.find(s[i]) != hm.end()) {
                hm[s[i]]++;
            } else {
                hm[s[i]] = 1;
            }
        }

        for (auto entry : hm) {
            minHeap.push(entry);
        }

        while (!minHeap.empty()) {
            pair<char, int> current = minHeap.top();
            minHeap.pop();
            for (int i = 0; i < current.second; i++) {
                result += current.first;
            }
        }

        return result;
    }

    struct compare {
      bool operator()(pair<char,int> a, pair<char,int> b) {
          return a.second < b.second;
      }
    };
};
