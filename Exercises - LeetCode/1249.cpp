class Solution {
public:
    string minRemoveToMakeValid(string s) {
       stack<int> st;
       for (auto i = 0; i < s.size(); ++i) {
          if (s[i] == '(') st.push(i);
          if (s[i] == ')') {
            if (!st.empty()) st.pop();
            else s[i] = '*';
         }
      }
      while (!st.empty()) { // case -> ))((
         s[st.top()] = '*';
         st.pop();
      }
      s.erase(remove(s.begin(), s.end(), '*'), s.end()); //the remove method return the ranges, and we delete with the erase
      return s;
    }
};

// O(n)
// O(n)