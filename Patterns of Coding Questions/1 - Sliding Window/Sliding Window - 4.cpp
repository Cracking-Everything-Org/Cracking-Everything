Given a string, find the length of the longest substring in it with no more than K distinct characters.

Input: String="araaci", K=2
Output: 4
Explanation: The longest substring with no more than '2' distinct characters is "araa".

Input: String="araaci", K=1
Output: 2
Explanation: The longest substring with no more than '1' distinct characters is "aa".

Input: String="cbbebi", K=3
Output: 5
Explanation: The longest substrings with no more than '3' distinct characters are "cbbeb" & "bbebi".

int findLength(const string& str, int k) {
    int maxLength = 0;
    unordered_map<char, int> hm;
    int windowStart = 0;
    // TODO: Write your code here
    for(int windowEnd = 0; windowEnd<str.length(); windowEnd++){
      char rightChar = str[rightChar];
      hm[rightChar]++;

      while(hm.size() > k){
        char leftChar = str[windowStart];
        hm[leftChar]--;
        if(hm[leftChar] == 0){
          hm.erase(leftChar);
        }
        windowStart++;
      }
      maxLength = max(maxLength, windowEnd - windowStart + 1);
    }
    return maxLength;
  }
