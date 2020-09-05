class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int pushedIndex = 0;
        int poppedIndex = 0;
        while (poppedIndex < popped.size() && pushedIndex < pushed.size()) {
            if (pushed[pushedIndex] == popped[poppedIndex]) {
                pushedIndex++;
                poppedIndex++;
            } else {
                if (!stk.empty() && popped[poppedIndex] == stk.top()) {
                    stk.pop();
                    poppedIndex++;
                } else {
                    stk.push(pushed[pushedIndex]);
                    pushedIndex++;
                }
            }
        }

        while (!stk.empty() && poppedIndex < popped.size()) {
            if (stk.top() != popped[poppedIndex]) {
                return false;
            }
            stk.pop();
            poppedIndex++;
        }

        return stk.empty();

    }
};
