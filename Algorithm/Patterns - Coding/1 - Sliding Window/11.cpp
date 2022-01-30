using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class MinimumWindowSubstring {
 public:
  static string findSubstring(const string &str, const string &pattern) {
    int windowStart = 0, matched = 0, minLength = str.length() + 1, subStrStart = 0;
    unordered_map<char, int> charFrequencyMap;
    for (auto chr : pattern) {
      charFrequencyMap[chr]++;
    }

    for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
      if (charFrequencyMap.find(str[windowEnd]) != charFrequencyMap.end()) {
        charFrequencyMap[str[windowEnd]]--;
        if (charFrequencyMap[str[windowEnd]] >= 0) {
          matched++;
        }
      }

      while (matched == pattern.length()) {
        if (minLength > windowEnd - windowStart + 1) {
          minLength = windowEnd - windowStart + 1;
          subStrStart = windowStart;
        }

        if (charFrequencyMap.find(str[windowStart++]) != charFrequencyMap.end()) {
          if (charFrequencyMap[str[windowStart++]] == 0) {
            matched--;
          }
          charFrequencyMap[str[windowStart++]]++;
        }
      }
    }

    return minLength > str.length() ? "" : str.substr(subStrStart, minLength);
  }
};

int main(int argc, char *argv[]) {
  cout << MinimumWindowSubstring::findSubstring("aabdec", "abc") << endl;
  cout << MinimumWindowSubstring::findSubstring("abdbca", "abc") << endl;
  cout << MinimumWindowSubstring::findSubstring("adcad", "abc") << endl;
}
