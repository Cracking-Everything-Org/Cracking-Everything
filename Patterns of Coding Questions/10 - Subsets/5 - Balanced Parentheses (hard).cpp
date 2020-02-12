Problem Statement #
For a given number ‘N’, write a function to generate all combination of ‘N’ pairs of balanced parentheses.

Example 1:

Input: N=2
Output: (()), ()()

Example 2:

Input: N=3
Output: ((())), (()()), (())(), ()(()), ()()()

vector<string> generateValidParentheses(int num) {
    vector<string> result;
    queue<ParenthesesString> queue;
    queue.push({"", 0, 0});
    while (!queue.empty()) {
      ParenthesesString ps = queue.front();
      queue.pop();
      // if we've reached the maximum number of open and close parentheses, add to the result
      if (ps.openCount == num && ps.closeCount == num) {
        result.push_back(ps.str);
      } else {
        if (ps.openCount < num) {  // if we can add an open parentheses, add it
          queue.push({ps.str + "(", ps.openCount + 1, ps.closeCount});
        }

        if (ps.openCount > ps.closeCount) {  // if we can add a close parentheses, add it
          queue.push({ps.str + ")", ps.openCount, ps.closeCount + 1});
        }
      }
    }
    return result;
  }

Time complexity #
Let’s try to estimate how many combinations we can have for ‘N’ pairs of balanced parentheses. If we don’t care for the ordering - that ) can only come after ( - then we have two options for every position, i.e., either put open parentheses or close parentheses. This means we can have a maximum of 2^N combinations. Because of the ordering, the actual number will be less than 2^N.

Space complexity #
All the additional space used by our algorithm is for the output list. Since we can’t have more than O(2^N) combinations, the space complexity of our algorithm is O(N*2^N).
