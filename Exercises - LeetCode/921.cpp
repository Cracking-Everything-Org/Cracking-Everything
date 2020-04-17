class Solution {
public:
    int minAddToMakeValid(string S) {
        // balance
        int bal = 0;
        int count = 0;
        for (int i = 0; i < S.length(); i++) {
            bal += S[i] == '(' ? 1 : -1;
            if (bal == -1) {
                count++;
                bal++;
            }
        }
        return count + bal;
    }
};
