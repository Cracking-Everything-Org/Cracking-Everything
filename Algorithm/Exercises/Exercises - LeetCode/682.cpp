class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> scores;
        char operation;
        
        for (int i = 0; i < ops.size(); i++) {
            operation = getOp(ops[i]);
            if (operation == 'C') {
                scores.pop();
            } else if (operation == 'D') {
                scores.push(scores.top() * 2);
            } else if (operation == '+') {
                int top = scores.top();
                scores.pop();
                int result = scores.top() + top;
                scores.push(top);
                scores.push(result);
            } else {
                scores.push(stoi(ops[i]));
            }
        }
        
        int finalScore = 0;
        while (!scores.empty()) {
            finalScore += scores.top();
            scores.pop();
        }
        return finalScore;
    }
    
    char getOp(string operation) {
        if (operation[0] == 'C' || operation[0] == 'D' || operation[0] == '+') {
            return operation[0];
        }
        return 'x';
    }
};