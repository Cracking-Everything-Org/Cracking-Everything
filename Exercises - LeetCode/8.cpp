class Solution {
public:
    int myAtoi(string str) {

        int start = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] != ' ') {
                start = i;
                break;
            }
        }
        string strim = str.substr(start);

        long out = 0;
        bool negative = strim[0] == '-' ? true : false;
        if (!isdigit(strim[0]) && (strim[0] != '-' && strim[0] != '+')) return out;
        if (isdigit(strim[0])) out += (strim[0] - '0');
        for (int i = 1; i < strim.length(); i++) {
            if (!isdigit(strim[i])) {
                break;
            }
            out = (out * 10) + (strim[i] - '0');
            if (!negative && out >= 2147483647) return INT_MAX;
            if (negative && out >= 2147483648) return INT_MIN;
        }
        return negative ? (int)(-1 * out) : (int)out;
    }
};
