There is a dictionary containing words from an alien language for which we don’t know the ordering of the characters. Write a method to find the correct order of characters in the alien language.

Example 1:

Input: Words: ["ba", "bc", "ac", "cab"]
Output: bac
Explanation: Given that the words are sorted lexicographically by the rules of the alien language, so
from the given words we can conclude the following ordering among its characters:

1. From "ba" and "bc", we can conclude that 'a' comes before 'c'.
2. From "bc" and "ac", we can conclude that 'b' comes before 'a'

From the above two points, we can conclude that the correct character order is: "bac"
Example 2:

Input: Words: ["cab", "aaa", "aab"]
Output: cab
Explanation: From the given words we can conclude the following ordering among its characters:

1. From "cab" and "aaa", we can conclude that 'c' comes before 'a'.
2. From "aaa" and "aab", we can conclude that 'a' comes before 'b'

From the above two points, we can conclude that the correct character order is: "cab"
Example 3:

Input: Words: ["ywx", "wz", "xww", "xz", "zyy", "zwz"]
Output: ywxz
Explanation: From the given words we can conclude the following ordering among its characters:

1. From "ywx" and "wz", we can conclude that 'y' comes before 'w'.
2. From "wz" and "xww", we can conclude that 'w' comes before 'x'.
3. From "xww" and "xz", we can conclude that 'w' comes before 'z'
4. From "xz" and "zyy", we can conclude that 'x' comes before 'z'
5. From "zyy" and "zwz", we can conclude that 'y' comes before 'w'

From the above five points, we can conclude that the correct character order is: "ywxz"

string findOrder(const vector<string> &words) {
  string sortedOrder;
  // TODO: Write your code here
  unordered_map<char, vector<char>> adjacencyList;
  unordered_map<char, int> inDegree;

  for (auto word : words) {
    for (char character : word) {
      inDegree[character] = 0;
      adjacencyList[character] = vector<char>();
    }
  }

  for (int i = 0 ; i < words.size() - 1 ; i++) {
    string first = words[i];
    string second = words[i+1];
    for (int j = 0 ; j < first.length(); j++) {
      if (first[j] < second[j]) {
        adjacencyList[first[j]].push_back(second[j]);
        inDegree[second[j]]++;
        break;
      }
    }
  }

  queue<char> sources;
  for (auto entry : inDegree) {
    if (entry.second == 0) {
      sources.push(entry.first);
    }
  }

  while (!sources.empty()) {
    int vertex = sources.front();
    sources.pop();
    sortedOrder.push_back(vertex);
    vector<char> children = adjacencyList[vertex];
    for (auto child : children) {
      inDegree[child]--;
      if(inDegree[child] == 0){
        sources.push(child);
      }
    }
  }

  return sortedOrder;
}

Time complexity #
In step ‘d’, each task can become a source only once and each edge (a rule) will be accessed and removed once. Therefore, the time complexity of the above algorithm will be O(V+E), where ‘V’ is the total number of different characters and ‘E’ is the total number of the rules in the alien language. Since, at most, each pair of words can give us one rule, therefore, we can conclude that the upper bound for the rules is O(N) where ‘N’ is the number of words in the input. So, we can say that the time complexity of our algorithm is O(V+N).

Space complexity #
The space complexity will be O(V+N), since we are storing all of the rules for each character in an adjacency list.
