class Solution {
public:
    string decodeString(string s) {
        stack<string> stk;
        int num = 0;
        string curr = "";
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                num = (num * 10) + s[i] - '0';
            }
            else if (isalpha(s[i])) {
                curr.push_back(s[i]);
            }
            else if (s[i]=='[') {
                stk.push(curr);
                stk.push(to_string(num));
                curr = "";
                num = 0;
            }
            else {
                num = stoi(stk.top());
                stk.pop();
                
                string prev = stk.top(), aux = "";
                stk.pop();
                for (int i = 0; i < num; i++) {
                    aux += curr;
                }
                num = 0;
                curr = prev + aux;
            }
        }
        return curr;
    }
};