/*
1. Given a string s and a dictionary containing a list of words, write a function to break the string completely
into valid words. Print all such possible sentences. The same word in the dictionary may be reused multiple times.

Input = "catsanddog"
dictionary = ["cat", "cats", "and", "sand", "dog"]
Output = "cat", "sand, "dog"
        "cats", "and", "dog"
*/

vector<string> wordBreak(string given, unordered_set<string> dictionary) {
  vector<> ans;
  wb(ans, given, dictionary, "", 0);
  return ans;
}

void wb(string input, unordered_set<string> dictionary, vector<string> partial) {
  if (input.length() == 0) {
    for (auto s : partial) {
      cout << s << " ";
    }
    cout << endl;
  }
  for (int i = 0; i < input.length(); i++) {
    string word = input.substr(0, i + 1);
    if (dictionary.count(word)) {
      partial.push_back(current);
      wb(input.substr(i + 1), dictionary, partial);
      partial.pop_back(current);
    }
  }
}
