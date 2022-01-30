class Solution {
public:
    int calculate(string s) {
        int tail = 0; // last number
        char op = '+'; // first operator
        int result = 0;
        int currentNum = 0;
        int n = s.length();

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (c == ' ') continue;

            if (isdigit(c)) {
                currentNum = (int)(c - '0');
                // necesitamos seguir mirando si es un numero de más de una cifra
                while (i + 1 < n && isdigit(s[i+1])) {
                    currentNum = currentNum * 10 + (int)(s[i+1] - '0');
                    i++;
                }

                // si es suma o resta, actualizo el tail
                if (op == '+') {
                    result += tail;
                    tail = currentNum;
                    break;
                }
                if (op == '-') {
                    result += -tail;
                    tail = currentNum;
                    break;
                }
                if (op == '*') {
                    tail *= currentNum;
                    break;
                }
                if (op == '/') {
                    tail /= currentNum;
                    break;
                }
            } else {
                op = s[c];
            }
        }
        return result + tail;
    }
};
