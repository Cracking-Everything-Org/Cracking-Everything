public int findMPPCuts(String st) {
  // isPalindrome[i][j] will be 'true' if the string from index 'i' to index 'j' is a palindrome
  boolean[][] isPalindrome = new boolean[st.length()][st.length()];

  // every string with one character is a palindrome
  for (int i = 0; i < st.length(); i++)
    isPalindrome[i][i] = true;

  // populate isPalindrome table
  for (int startIndex = st.length() - 1; startIndex >= 0; startIndex--) {
    for (int endIndex = startIndex + 1; endIndex < st.length(); endIndex++) {
      if (st.charAt(startIndex) == st.charAt(endIndex)) {
        // if it's a two character string or if the remaining string is a palindrome too
        if (endIndex - startIndex == 1 || isPalindrome[startIndex + 1][endIndex - 1]) {
          isPalindrome[startIndex][endIndex] = true;
        }
      }
    }
  }

  // now lets populate the second table, every index in 'cuts' stores the minimum cuts needed
  // for the substring from that index till the end
  int[] cuts = new int[st.length()];
  for (int startIndex = st.length() - 1; startIndex >= 0; startIndex--) {
    int minCuts = st.length(); // maximum cuts
    for (int endIndex = st.length() - 1; endIndex >= startIndex; endIndex--) {
      if (isPalindrome[startIndex][endIndex]) {
        // we can cut here as we got a palindrome
        // also we dont need any cut if the whole substring is a palindrome
        minCuts = (endIndex == st.length() - 1) ? 0 : Math.min(minCuts, 1 + cuts[endIndex + 1]);
      }
    }
    cuts[startIndex] = minCuts;
  }

  return cuts[0];
}
