/*
1. Given a string, write a function to print out all its anagrams.

Input = "god",
Output = "god", "gdo", "dog", "dgo", "ogd", "odg"
*/

vector<string> anagrams(string givenString) {
  vector<string> ans;
  vector<bool> used;
  getAnagrams(ans, givenString, "", used);
  return ans;
}

void getAnagrams(vector<string> ans, string givenString, string partialString, vector<bool> used) {
  if (partialString.length() == givenString.length()) {
    ans.push_back(partialString);
  }
  for (int i = 0; i < givenString.length(); i++) {
    if (used[i]) {
      continue;
    }
    used[i] = true;
    getAnagrams(ans, givenString, partialString += givenString[i], used);
    used[i] = false;
    getAnagrams(ans, givenString, partialString, used);
  }
}
