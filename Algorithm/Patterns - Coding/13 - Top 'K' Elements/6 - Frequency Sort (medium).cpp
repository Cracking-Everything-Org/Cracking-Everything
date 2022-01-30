Given a string, sort it based on the decreasing frequency of its characters.

Example 1:

Input: "Programming"
Output: "rrggmmPiano"
Explanation: 'r', 'g', and 'm' appeared twice, so they need to appear before any other character.
Example 2:

Input: "abcbab"
Output: "bbbaac"
Explanation: 'b' appeared three times, 'a' appeared twice, and 'c' appeared only once.


public:
struct valueCompare {
  bool operator()(const pair<char, int> &x, const pair<char, int> &y) {
    return y.second > x.second;
  }
};

static string sortCharacterByFrequency(const string &str) {
  // find the frequency of each character
  unordered_map<char, int> characterFrequencyMap;
  for (char chr : str) {
    characterFrequencyMap[chr]++;
  }

  priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare> maxHeap;

  // add all characters to the max heap
  for (auto entry : characterFrequencyMap) {
    maxHeap.push(entry);
  }

  // build a string, appending the most occurring characters first
  string sortedString = "";
  while (!maxHeap.empty()) {
    auto entry = maxHeap.top();
    maxHeap.pop();
    for (int i = 0; i < entry.second; i++) {
      sortedString += entry.first;
    }
  }

  return sortedString;
}


Time complexity #
The time complexity of the above algorithm is O(D*logD) where ‘D’ is the number of distinct characters in the input string. This means, in the worst case, when all characters are unique the time complexity of the algorithm will be O(N∗logN) where ‘N’ is the total number of characters in the string.

Space complexity #
The space complexity will be O(N), as in the worst case, we need to store all the ‘N’ characters in the HashMap.
