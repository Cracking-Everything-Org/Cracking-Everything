class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k <= 1) return s;

        unordered_map<char, int> frequency;
        priority_queue<pair<char, int>, vector<pair<char, int>>, compare> maxHeap;

        for (int i = 0; i < s.length(); i++) {
            frequency[s[i]]++;
        }

        for (auto entry : frequency) {
            maxHeap.push(entry);
        }

        queue<pair<char, int>> queue;
        string resultString;
        while (!maxHeap.empty()) {
            pair<char, int> current = maxHeap.top();
            maxHeap.pop();
            resultString += current.first;
            current.second--;
            queue.push(current);
            if (queue.size() == k) {
                pair<char, int> frontElement = queue.front();
                queue.pop();
                if (frontElement.second > 0) {
                    maxHeap.push(frontElement);
                }
            }
        }

        return resultString.length() == s.length() ? resultString :  "";
    }

    struct compare {
      bool operator()(pair<int, char> a, pair<int, char> b) {
          return a.second < b.second;
      }
    };
};
