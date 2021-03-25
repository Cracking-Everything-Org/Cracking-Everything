class LongestSubstringKDistinct {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0;
    int currentLength = 0;
    unordered_map<char, int> hm;
    int start = 0;
    for (int end = 0; end < str.length(); end++) {
      hm[str[end]]++;
      currentLength++;
      while ((int)hm.size() > k) {
        hm[str[start]]--;
        if (hm[str[start]] == 0) {
          hm.erase(str[start]);
        }
        currentLength--;
        start++;
      }
      maxLength = max(maxLength, currentLength);
    }
    return maxLength;
  }
};