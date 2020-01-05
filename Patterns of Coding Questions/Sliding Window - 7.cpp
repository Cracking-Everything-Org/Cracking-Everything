Given a string with lowercase letters only, if you are allowed to replace no more than ‘k’ letters with any letter, find the length of the longest substring having the same letters after replacement.

Input: String="aabccbb", k=2
Output: 5
Explanation: Replace the two 'c' with 'b' to have a longest repeating substring "bbbbb".

Input: String="abbcb", k=1
Output: 4
Explanation: Replace the 'c' with 'b' to have a longest repeating substring "bbbb".

Input: String="abccde", k=1
Output: 3
Explanation: Replace the 'b' or 'd' with 'c' to have the longest repeating substring "ccc".

int findLength(const string& str, int k) {
    int maxLength = 0;
    // TODO: Write your code here
    unordered_map<char, int> ht;
    int windowStart = 0;
    int maxRepeatLetterCount = 0;
    for (int windowEnd = 0; windowEnd < str.length(); windowEnd++){
      //add
      char rightChar = str[windowEnd];
      ht[rightChar]++;
      maxRepeatLetterCount = max(maxRepeatLetterCount, ht[rightChar]);
      //shrink
      if(windowEnd - windowStart + 1 - maxRepeatLetterCount > k){
        char leftChar = str[windowStart];
        ht[leftChar]--;
        if(ht[leftChar] == 0) ht.erase(leftChar);
        windowStart++;
      }
      maxLength = max(maxLength, windowEnd - windowStart + 1);
    }
    return maxLength;
  }

Time Complexity #
The time complexity of the above algorithm will be O(N) where ‘N’ is the number of letters in the input string.

Space Complexity #
As we are expecting only the lower case letters in the input string, we can conclude that the space complexity will be O(26), to store each letter’s frequency in the HashMap, which is asymptotically equal to O(1).
