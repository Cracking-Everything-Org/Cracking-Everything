Problem Statement #
Given a string, find all of its permutations preserving the character sequence but changing case.

Example 1:

Input: "ad52"
Output: "ad52", "Ad52", "aD52", "AD52"
Example 2:

Input: "ab7c"
Output: "ab7c", "Ab7c", "aB7c", "AB7c", "ab7C", "Ab7C", "aB7C", "AB7C"

vector<string> findLetterCaseStringPermutations(const string& str) {
    vector<string> permutations;
    if (str == "") {
      return permutations;
    }

    permutations.push_back(str);
    // process every character of the string one by one
    for (int i = 0; i < str.length(); i++) {
      if (isalpha(str[i])) {  // only process characters, skip digits
        // we will take all existing permutations and change the letter case appropriately
        int n = permutations.size();
        for (int j = 0; j < n; j++) {
          vector<char> chs(permutations[j].begin(), permutations[j].end());
          // if the current character is in upper case change it to lower case or vice versa
          if (isupper(chs[i])) {
            chs[i] = tolower(chs[i]);
          } else {
            chs[i] = toupper(chs[i]);
          }
          permutations.push_back(string(chs.begin(), chs.end()));
        }
      }
    }
    return permutations;
  }


Time complexity #
Since we can have 2^N permutations at the most and while processing each permutation we convert it into a character array, the overall time complexity of the algorithm will be O(N*2^N)

Space complexity #
All the additional space used by our algorithm is for the output list. Since we can have a total of O(2^N) permutations, the space complexity of our algorithm is O(N*2^N).
