class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> squares;
        stack<int> stk;
        int leftPointer = 0;
        int rightPointer = A.size()-1;
        while (leftPointer <= rightPointer) {
            if (pow(A[leftPointer],2) >= pow(A[rightPointer],2)) {
                stk.push(pow(A[leftPointer],2));
                leftPointer++;
            } else {
                stk.push(pow(A[rightPointer],2));
                rightPointer--;
            }
        }
        while (!stk.empty()) {
            squares.push_back(stk.top());
            stk.pop();
        }
        return squares;
    }
};
