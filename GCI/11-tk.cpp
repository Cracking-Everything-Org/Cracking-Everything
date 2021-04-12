class RearrangeString {
 struct compare {
   bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
     return a.second < b.second;
   }
 };

 public:
  static string rearrangeString(const string &str) {
    priority_queue<pair<char, int>, vector<pair<char, int>>, compare> minHeap;
    unordered_map<char, int> hm;
    for (char c : str) {
      hm[c]++;
    }
    for (auto entry : hm) {
      minHeap.push(entry);
    }
    string result = "";
    pair<char, int> previousEntry(-1, -1);
    while (!minHeap.empty()) {
      pair<char, int> current = minHeap.top();
      minHeap.pop();
      if (previousEntry.second > 0) {
        minHeap.push(previousEntry);
      }
      result += current.first;
      current.second--;
      previousEntry = current;
    }
    return result.length() == str.length() ? result : "";
  }
};
