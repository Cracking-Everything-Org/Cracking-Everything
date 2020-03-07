Given a string, find the length of the longest substring which has no repeating characters.

Input: String="aabccbb"
Output: 3
Explanation: The longest substring without any repeating characters is "abc".

Input: String="abbbb"
Output: 2
Explanation: The longest substring without any repeating characters is "ab".

Input: String="abccde"
Output: 3
Explanation: Longest substrings without any repeating characters are "abc" & "cde".

int findLength(const string& str) {
    int maxLength = 0;
    int windowStart = 0;
    unordered_map<char, int> ht;
    // TODO: Write your code here
    for(int windowEnd = 0; windowEnd<str.length(); windowEnd++){
      char rightChar = str[windowEnd];
      ht[rightChar]++;
      while(ht[rightChar]>1){
        char leftChar = str[windowStart];
        ht[leftChar]--;
        if(ht[leftChar] == 0)  ht.erase(leftChar);
        windowStart++;
      }
      maxLength = max(maxLength, windowEnd - windowStart + 1);
    }
    return maxLength;
  }

Time Complexity #
The time complexity of the above algorithm will be O(N).

Space Complexity #
The space complexity of the algorithm will be O(K) where K is the number of distinct characters in the input string. This also means K<=N, because in the worst case, the whole string might not have any repeating character so the entire string will be added to the HashMap. Having said that, since we can expect a fixed set of characters in the input string (e.g., 26 for English letters), we can say that the algorithm runs in fixed space O(1); in this case, we can use a fixed-size array instead of the HashMap.
