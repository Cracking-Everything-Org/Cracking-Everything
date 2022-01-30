using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class LongestSubstringKDistinct {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0;
    unordered_map<char, int> hm;
    
    int start = 0;
    for (int end = 0; end < str.length(); end++) {
      hm[str[end]]++;

      while (hm.size() > k) {
        hm[str[start]]--;
        if (hm[str[start]] == 0) {
          hm.erase(str[start]);
        }
        start++;
      }
      maxLength = max(maxLength, end - start + 1);
    }
    return maxLength;
  }
};
