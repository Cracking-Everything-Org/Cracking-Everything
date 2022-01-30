
class FrequencySort {
 struct compare {
   bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
     return a.second < b.second;
   }
 };

 public:
  static string sortCharacterByFrequency(const string &str) {
    string sortedString = "";
    unordered_map<char, int> hm;
    priority_queue<pair<char, int>, vector<pair<char, int>>, compare> minHeap;
    for (char n : str) {
      hm[n]++;
    }
    for (auto entry : hm) {
      minHeap.push(entry);
    }
    while (!minHeap.empty()) {
      pair<char, int> current = minHeap.top();
      for (int i = 0; i < current.second; i++) {
        sortedString += current.first;
      }
      minHeap.pop();
    }
    return sortedString;
  }
};
