class NoRepeatSubstring {
 public:
  static int findLength(const string& str) {
    int maxLength = 0;
    int currentLength = 0;
    int start = 0;
    unordered_map<char, int> hm;
    for (int end = 0; end < str.length(); end++) {
      currentLength++;
      hm[str[end]]++;
      while (hm[str[end]] >= 2) {
        hm[str[start]]--;
        if (hm[str[start]] == 0) {
          hm.erase(str[start]);
        }
        start++;
        currentLength--;
      }

      maxLength = max(maxLength, currentLength);
    }

    return maxLength;
  }
};