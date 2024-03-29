/*
1. Given a string, write a function to print out all its anagrams.

Input = "god",
Output = "god", "gdo", "dog", "dgo", "ogd", "odg"
*/

vector<string> anagrams(string givenString) {
  vector<string> ans;
  vector<bool> used;
  sort(givenString.begin(), givenString.end());
  getAnagrams(ans, givenString, "", used, 0);
  return ans;
}

void getAnagrams(vector<string> ans, string given, string partial, vector<bool> used, int index) {
  if (index == givenString.length()) {
    ans.push_back(partialString);
  }
  for (int i = 0; i < givenString.length(); i++) {
    if (!used[i] && !(i > 0 && given[i] == given[i - 1] && !used[i - 1])) {
      used[i] = true;
      getAnagrams(ans, given, partial += given[i], used, index + 1);
      used[i] = false;
    }
  }
}
