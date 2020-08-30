#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> A) {
  if (A.size() == 0) return 0;
  unordered_map<string, bool> hm;
  for (int i = 0; i < A.size(); i++) {
    if (A[i][0] == '+') {
      if (hm.find(A[i]) == hm.end()) {
        hm[A[i]] = true;
      }
    }
  }
  return hm.size();
}

vector<string> splitAndRemoveQuotes(string s, char sep) {
  vector<string> words;
  string word;
  istringstream wordStream(s);
  while (getline(wordStream, word, sep)) {
    words.push_back(word.substr(1, word.length() - 2));
  }
  return words;
}

int main() {
  // Read from stdin, solve the problem, and write the answer to stdout.
  string input;
  cin >> input;
  string removedBrackets = input.substr(1, input.length() - 2);
  cout << solution(splitAndRemoveQuotes(removedBrackets, ','));
}
