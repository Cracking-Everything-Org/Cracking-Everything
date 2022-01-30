using namespace std;

#include <iostream>
#include <unordered_map>
#include <vector>

class MaxFruitCountOf2Types {
 public:
  static int findLength(const vector<char>& arr) {
    int maxLength = 0;
    unordered_map<char, int> hm;
    
    int start = 0;
    for (int end = 0; end < arr.size(); end++) {
      hm[arr[end]]++;

      while (hm.size() > 2) {
        hm[arr[start]]--;
        if (hm[arr[start]] == 0) {
          hm.erase(arr[start]);
          start++;
        }
      }

      maxLength = max(maxLength, end - start + 1);
    }
    return maxLength;
  }
};
