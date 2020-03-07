Given a string and a pattern, find the smallest substring in the given string which has all the characters of the given pattern.

Input: String="aabdec", Pattern="abc"
Output: "abdec"
Explanation: The smallest substring having all characters of the pattern is "abdec"

Input: String="abdabca", Pattern="abc"
Output: "abc"
Explanation: The smallest substring having all characters of the pattern is "abc".

Input: String="adcad", Pattern="abc"
Output: ""
Explanation: No substring in the given string has all characters of the pattern.

string findSubstring(const string &str, const string &pattern) {
    // TODO: Write your code here
    int windowStart = 0;
    int matched = 0;
    int minLength = str.length() + 1;
    int subStrStart = 0;
    unordered_map<char, int> ht;
    for (int i=0; i<pattern.length(); i++){
      ht[pattern[i]]++;
    }
    for (int windowEnd =0; windowEnd<str.length(); windowEnd++) {
      char rightChar = str[windowEnd];
      if(ht.find(rightChar)!=ht.end()){
        ht[rightChar]--;
        if(ht[rightChar]>=0){
          matched++;
        }
      }

      while(matched == pattern.length()) {
        if(minLength > windowEnd - windowStart + 1){
          minLength = windowEnd - windowStart + 1;
          subStrStart = windowStart;
        }

        char leftChar = str[windowStart++];
        if(ht.find(leftChar)!= ht.end()){
          if(ht[leftChar] == 0){
            matched--;
          }
          ht[leftChar]++;
        }
      }
    }
    return minLength > str.length() ? "" : str.substr(subStrStart, minLength);
  }

  Time Complexity #
The time complexity of the above algorithm will be O(N + M) where ‘N’ and ‘M’ are the number of characters in the input string and the pattern respectively.

Space Complexity #
The space complexity of the algorithm is O(M) since in the worst case, the whole pattern can have distinct characters which will go into the HashMap. In the worst case, we also need O(N) space for the resulting substring, which will happen when the input string is a permutation of the pattern.
