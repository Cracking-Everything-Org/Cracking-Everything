class Solution {
public:
    string multiply(string num1, string num2) {
        // like elementary school
        int m = num1.length();
        int n = num2.length();
        vector<int> ans(n + m, 0);
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = ans[i + j + i] + mul; // i + j + 1 -> last position
                ans[i + j] += sum / 10;
                ans[i + j + 1] = sum % 10;
            }
        }

        string result = "";
        int leadingZeros = 0;
        while (leadingZeros < ans.size()) {
            if (ans[leadingZeros] == 0) {
                leadingZeros++;
            } else {
                break;
            }
        }
        for (int i = leadingZeros; i < ans.size(); i++){
            result += to_string(ans[i]);
        }
        return result;
    }
};
