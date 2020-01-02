class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int firstOperand;
        int secondOperand;
        stack<int> stk;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                secondOperand = stk.top();
                stk.pop();
                firstOperand = stk.top();
                stk.pop();
                stk.push(firstOperand + secondOperand);
            } else if(tokens[i]=="-"){
                secondOperand = stk.top();
                stk.pop();
                firstOperand = stk.top();
                stk.pop();
                stk.push(firstOperand - secondOperand);
            } else if(tokens[i]=="*"){
                secondOperand = stk.top();
                stk.pop();
                firstOperand = stk.top();
                stk.pop();
                stk.push(firstOperand * secondOperand);
            } else if(tokens[i]=="/") {
                secondOperand = stk.top();
                stk.pop();
                firstOperand = stk.top();
                stk.pop();
                stk.push(firstOperand / secondOperand);
            } else {
                stk.push(stoi(tokens[i]));
            }
        }
        int result = stk.top();
        stk.pop();
        return result;
    }
};
