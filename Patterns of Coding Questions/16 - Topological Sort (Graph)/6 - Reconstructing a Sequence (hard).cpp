Given a sequence originalSeq and an array of sequences, write a method to find if originalSeq can be uniquely reconstructed from the array of sequences.

Unique reconstruction means that we need to find if originalSeq is the only sequence such that all sequences in the array are subsequences of it.

Example 1:

Input: originalSeq: [1, 2, 3, 4], seqs: [[1, 2], [2, 3], [3, 4]]
Output: true
Explanation: The sequences [1, 2], [2, 3], and [3, 4] can uniquely reconstruct
[1, 2, 3, 4], in other words, all the given sequences uniquely define the order of numbers
in the 'originalSeq'.
Example 2:

Input: originalSeq: [1, 2, 3, 4], seqs: [[1, 2], [2, 3], [2, 4]]
Output: false
Explanation: The sequences [1, 2], [2, 3], and [2, 4] cannot uniquely reconstruct
[1, 2, 3, 4]. There are two possible sequences we can construct from the given sequences:
1) [1, 2, 3, 4]
2) [1, 2, 4, 3]
Example 3:

Input: originalSeq: [3, 1, 4, 2, 5], seqs: [[3, 1, 5], [1, 4, 2, 5]]
Output: true
Explanation: The sequences [3, 1, 5] and [1, 4, 2, 5] can uniquely reconstruct
[3, 1, 4, 2, 5].

bool canConstruct(const vector<int> &originalSeq, const vector<vector<int>> &sequences) {
  // TODO: Write your code here
  vector<int> sortedList;

  if (originalSeq.size() <= 0) {
    return false;
  }

  unordered_map<int, vector<int>> adjacencyList;
  unordered_map<int, int> inDegree;

  for (auto seq : sequences) {
    for (auto num : seq) {
      adjacencyList[num] = vector<int>();
      inDegree[num] = 0;
    }
  }

  for (auto seq : sequences) {
    for (int i=0; i<seq.size()-1; i++) {
      int first = seq[i];
      int second = seq[i+1];
      adjacencyList[first].push_back(second);
      inDegree[second]++;
    }
  }

  queue<int> sources;
  for (auto entry : inDegree) {
    if (entry.second == 0) {
      sources.push(entry.first);
    }
  }

  while (!sources.empty()) {
    if (sources.size() > 1) {
      return false;
    }
    int vertex = sources.front();
    sources.pop();
    sortedList.push_back(vertex);
    vector<int> children = adjacencyList[vertex];
    for (auto child : children) {
      inDegree[child]--;
      if (inDegree[child]==0) {
        sources.push(child);
      }
    }
  }

  if (sortedList.size() != originalSeq.size()) return false;
  for (int i=0; i<sortedList.size(); i++) {
    if (sortedList[i] != originalSeq[i]) return false;
  }

  return true;
}

Time complexity #
In step ‘d’, each number can become a source only once and each edge (a rule) will be accessed and removed once. Therefore, the time complexity of the above algorithm will be O(V+E), where ‘V’ is the count of distinct numbers and ‘E’ is the total number of the rules. Since, at most, each pair of numbers can give us one rule, we can conclude that the upper bound for the rules is O(N) where ‘N’ is the count of numbers in all sequences. So, we can say that the time complexity of our algorithm is O(V+N).

Space complexity #
The space complexity will be O(V+N), since we are storing all of the rules for each number in an adjacency list.
