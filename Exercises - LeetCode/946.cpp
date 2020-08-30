class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() != popped.size()) {
            return false;
        }

        stack<int> stk;
        int firstPointer = 0;
        int secondPointer = 0;

        while (firstPointer < pushed.size() && secondPointer < popped.size()) {

            if (pushed[firstPointer] == popped[secondPointer]) {
                firstPointer++;
                secondPointer++;
            } else {
                if (!stk.empty() && stk.top() == popped[secondPointer]) {
                    stk.pop();
                    secondPointer++;
                } else {
                    stk.push(pushed[firstPointer]);
                    firstPointer++;
                }
            }
        }

        while (secondPointer < popped.size() && !stk.empty()) {
            if (popped[secondPointer] != stk.top()) {
                return false;
            } else {
                secondPointer++;
                stk.pop();
            }
        }

        return stk.empty();
    }
};
