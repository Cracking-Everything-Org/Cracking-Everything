class MaxFruitCountOf2Types {
 public:
  static int findLength(const vector<char>& arr) {
    int maxLength = 0;
    int currentLength = 0;
    unordered_map<char, int> frequencyMap;
    int start = 0;
    for (int end = 0; end < arr.size(); end++) {
      currentLength++;
      frequencyMap[arr[end]]++;

      while ((int)frequencyMap.size() > 2) {
        frequencyMap[arr[start]]--;
        if (frequencyMap[arr[start]] == 0) {
          frequencyMap.erase(arr[start]);
        }
        start++;
        currentLength--;
      }
      maxLength = max(maxLength, currentLength);
    }
    return maxLength;
  }
};