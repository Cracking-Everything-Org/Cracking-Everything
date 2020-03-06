Given an array of characters where each character represents a fruit tree, you are given two baskets and your goal is to put maximum number of fruits in each basket. The only restriction is that each basket can have only one type of fruit.

You can start with any tree, but once you have started you can’t skip a tree. You will pick one fruit from each tree until you cannot, i.e., you will stop when you have to pick from a third fruit type.

Write a function to return the maximum number of fruits in both the baskets.

Input: Fruit=['A', 'B', 'C', 'A', 'C']
Output: 3
Explanation: We can put 2 'C' in one basket and one 'A' in the other from the subarray ['C', 'A', 'C']

Input: Fruit=['A', 'B', 'C', 'B', 'B', 'C']
Output: 5
Explanation: We can put 3 'B' in one basket and two 'C' in the other basket.
This can be done if we start with the second letter: ['B', 'C', 'B', 'B', 'C']

int findLength(const vector<char>& arr) {
    int maxLength = 0;
    // TODO: Write your code here
    unordered_map<char, int> ht;
    int windowStart = 0;
    for(int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
      //add the last
      char rightChar =  arr[windowEnd];
      ht[rightChar]++;
      //shrink
      while(ht.size()>2){
        char leftChar = arr[windowStart];
        ht[leftChar]--;
        if(ht[leftChar] == 0) ht.erase(leftChar);
        windowStart++;
      }
      maxLength = max(maxLength, windowEnd - windowStart + 1);
    }
    return maxLength;
  }

  Time Complexity #
  The time complexity of the above algorithm will be O(N).

  Space Complexity #
  The algorithm runs in constant space O(1).
