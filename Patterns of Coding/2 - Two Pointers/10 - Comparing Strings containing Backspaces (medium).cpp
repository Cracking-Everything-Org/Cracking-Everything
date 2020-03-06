Given two strings containing backspaces (identified by the character ‘#’), check if the two strings are equal.

Input: str1="xy#z", str2="xzz#"
Output: true
Explanation: After applying backspaces the strings become "xz" and "xz" respectively.

Input: str1="xy#z", str2="xyz#"
Output: false
Explanation: After applying backspaces the strings become "xz" and "xy" respectively.

Input: str1="xp#", str2="xyz##"
Output: true
Explanation: After applying backspaces the strings become "x" and "x" respectively.
In "xyz##", the first '#' removes the character 'z' and the second '#' removes the character 'y'.

Input: str1="xywrrmp", str2="xywrrmu#p"
Output: true
Explanation: After applying backspaces the strings become "xywrrmp" and "xywrrmp" respectively.

bool compare(const string &str1, const string &str2) {
  // use two pointer approach to compare the strings
  int index1 = str1.length() - 1, index2 = str2.length() - 1;
  while (index1 >= 0 || index2 >= 0) {
    int i1 = getNextValidCharIndex(str1, index1);
    int i2 = getNextValidCharIndex(str2, index2);

    if (i1 < 0 && i2 < 0) {  // reached the end of both the strings
      return true;
    }

    if (i1 < 0 || i2 < 0) {  // reached the end of one of the strings
      return false;
    }

    if (str1[i1] != str2[i2]) {  // check if the characters are equal
      return false;
    }

    index1 = i1 - 1;
    index2 = i2 - 1;
  }

  return true;
}

int getNextValidCharIndex(const string &str, int index) {
  int backspaceCount = 0;
  while (index >= 0) {
    if (str[index] == '#') {  // found a backspace character
      backspaceCount++;
    } else if (backspaceCount > 0) {  // a non-backspace character
      backspaceCount--;
    } else {
      break;
    }

    index--;  // skip a backspace or a valid character
  }
  return index;
}

Time complexity #
The time complexity of the above algorithm will be O(M+N) where ‘M’ and ‘N’ are the lengths of the two input strings respectively.

Space complexity #
The algorithm runs in constant space O(1).
