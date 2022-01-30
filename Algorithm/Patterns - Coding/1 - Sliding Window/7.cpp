using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class CharacterReplacement {
 public:
  static int findLength(const string &str, int k) {
    int start = 0;
    int maxLength = 0;
    int maxRepeatLetterCount = 0;
    unordered_map<char, int> letterFrequencyMap;

    for (int end = 0; end < str.length(); end++) {
      letterFrequencyMap[str[end]]++;
      maxRepeatLetterCount = max(maxRepeatLetterCount, letterFrequencyMap[str[end]]);

      if (end - start + 1 - maxRepeatLetterCount > k) {
        letterFrequencyMap[str[start]]--;
        start++;
      }

      maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
  }
};
