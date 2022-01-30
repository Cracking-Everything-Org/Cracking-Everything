using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class CharacterReplacement {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0;
    int start = 0;
    int maxRepeatLetterCount = 0;
    unordered_map<char, int> hm;
    for (int end = 0; end < str.length(); end++) {
      hm[str[end]]++;
      maxRepeatLetterCount = max(maxRepeatLetterCount, hm[str[end]]);
      if (end - start + 1 - maxRepeatLetterCount > k) {
        hm[str[start]]--;
        start++;
      }
      maxLength = max(maxLength, end - start + 1);
    }
    return maxLength;
  }
};
