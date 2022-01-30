Given a string and a pattern, find out if the string contains any permutation of the pattern.

Input: String="oidbcaf", Pattern="abc"
Output: true
Explanation: The string contains "bca" which is a permutation of the given pattern.

Input: String="odicf", Pattern="dc"
Output: false
Explanation: No permutation of the pattern is present in the given string as a substring.

Input: String="bcdxabcdy", Pattern="bcdyabcdx"
Output: true
Explanation: Both the string and the pattern are a permutation of each other.

Input: String="aaacb", Pattern="abc"
Output: true
Explanation: The string contains "acb" which is a permutation of the given pattern.

bool findPermutation(const string &str, const string &pattern) {
  // TODO: Write your code here
  int windowStart = 0;
  unordered_map<char, int> htP;
  for (int i=0; i <pattern.length(); i++){
    htP[pattern[i]]++;
  }
  unordered_map<char,int> htS;
  for (int windowEnd = 0; windowEnd < str.length(); windowEnd++){
    char rightChar = str[windowEnd];
    htS[rightChar] ++;
    while(htS[rightChar] > htP[rightChar]){
      char leftChar = str[windowStart];
      htS[leftChar]--;
      if(htS[leftChar] == 0) htS.erase(leftChar);
      windowStart++;
    }
    if (htS.size() == htP.size()) return true;
  }
  return false;
}
